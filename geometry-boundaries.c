/*
 * Calculate geometry boundaries from geometry files.  This is normally done
 * in the devas-visibility program.
 */

#include <stdlib.h>
#include <stdio.h>
/* #define	DeVAS_CHECK_BOUNDS */
#include "devas-image.h"
#include "read-geometry.h"
#include "geometry-discontinuities.h"
#include "devas-utils.h"
#include "devas-png.h"
#include "devas-license.h"	/* DeVAS open source license */

/* The following need tuning!!! */

#define	POSITION_PATCH_SIZE		3
#define	ORIENTATION_PATCH_SIZE		3
#define	POSITION_THRESHOLD		2 /* cm */
#define	ORIENTATION_THRESHOLD		20 /* degrees */

char	*Usage =
	  "geometry-boundaries coordinates xyz.txt dist.txt nor.txt gbound.png";
int	args_needed = 5;

/*
 * Arguments:
 *
 *   coordinates
 *
 *		A two line text file.  The first line specifies the units for
 *		the xyz.txt and dist.txt files. The second line is the same as
 *		the VIEW record in input.hdr.  See make-coordinates-file for
 *		information on how to create this file.
 *
 *   xyz.txt	A Radiance ASCII format file specifying the xyz model
 *		coordinates for each surface point in the model corresponding
 *		to the line of sight associated with each pixel in input.hdr.
 *
 *   dist.txt	A Radiance ASCII format file specifying the distance from the
 *		viewpoint to each surface point in the model corresponding to
 *		the line of sight associated with each pixel in input.hdr.
 *
 *   nor.txt	A Radiance ASCII format file specifying the surface normal in
 *		model coordinates for each surface point in the model
 *		corresponding to the line of sight associated with each pixel
 *		in input.hdr.  Note that the numeric values are unitless since
 *		they specify a unit normal.
 *
 *   gbound.png Output file.  Boundary elements are 255, non-boundary elements
 *   		are 0.
 */

int
main ( int argc, char *argv[] )
{
    char		*coordinates_file_name;
    char		*xyz_file_name;
    char		*dist_file_name;
    char		*nor_file_name;
    char		*geometry_boundaries_file_name;
    DeVAS_coordinates	*coordinates;
    DeVAS_XYZ_image	*xyz;
    DeVAS_float_image	*dist;
    DeVAS_XYZ_image	*nor;
    DeVAS_gray_image	*geometry_boundaries;
    int			row, col;

    /* Hardwired parameters for detection of geometry boundaries. */
    int			position_patch_size = POSITION_PATCH_SIZE;
    int			orientation_patch_size = ORIENTATION_PATCH_SIZE;
    int			position_threshold = POSITION_THRESHOLD;
    int			orientation_threshold = ORIENTATION_THRESHOLD;

    int			argpt = 1;

    if ( ( argc - argpt ) != args_needed ) {
    	fprintf ( stderr, "%s\n", Usage );
	return ( EXIT_FAILURE );	/* error return */
    }

    /* file names of geometry files */
    coordinates_file_name = argv[argpt++];
    xyz_file_name = argv[argpt++];
    dist_file_name = argv[argpt++];
    nor_file_name = argv[argpt++];
    geometry_boundaries_file_name = argv[argpt++];

    coordinates = DeVAS_coordinates_from_filename ( coordinates_file_name );
    xyz = DeVAS_geom3d_from_radfilename ( xyz_file_name );
    dist = DeVAS_geom1d_from_radfilename ( dist_file_name );
    nor = DeVAS_geom3d_from_radfilename ( nor_file_name );

    /* standardize distances (to cm) */
    standard_units_1D ( dist, coordinates );
    standard_units_3D ( xyz, coordinates );

    geometry_boundaries = geometry_discontinuities ( coordinates, xyz, dist,
	    nor, position_patch_size, orientation_patch_size,
	    position_threshold, orientation_threshold );

    for ( row = 0; row < DeVAS_image_n_rows ( geometry_boundaries ); row++ ) {
	for ( col = 0; col < DeVAS_image_n_cols ( geometry_boundaries );
		col++ ) {
	    if ( DeVAS_image_data ( geometry_boundaries, row, col ) ) {
		DeVAS_image_data ( geometry_boundaries, row, col ) = 255;
	    } else {
		DeVAS_image_data ( geometry_boundaries, row, col ) = 0;
	    }
	}
    }

    DeVAS_gray_image_to_filename_png ( geometry_boundaries_file_name,
	    geometry_boundaries );

    /* clean up */
    DeVAS_coordinates_delete ( coordinates );
    DeVAS_XYZ_image_delete ( xyz );
    DeVAS_float_image_delete ( dist );
    DeVAS_XYZ_image_delete ( nor );
    DeVAS_gray_image_delete ( geometry_boundaries );

    return ( EXIT_SUCCESS );	/* normal exit */
}
