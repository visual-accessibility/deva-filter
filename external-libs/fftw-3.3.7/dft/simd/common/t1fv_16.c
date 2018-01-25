/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Oct 29 08:16:50 EDT 2017 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 16 -name t1fv_16 -include dft/simd/t1f.h */

/*
 * This function contains 87 FP additions, 64 FP multiplications,
 * (or, 53 additions, 30 multiplications, 34 fused multiply/add),
 * 36 stack variables, 3 constants, and 32 memory accesses
 */
#include "dft/simd/t1f.h"

static void t1fv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DVK(KP414213562, +0.414213562373095048801688724209698078569671875);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 30)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 30), MAKE_VOLATILE_STRIDE(16, rs)) {
	       V T4, TW, T9, T19, TD, TI, TZ, T1a, Tf, Tk, Tl, T13, T1c, Tq, Tv;
	       V Tw, T16, T1d, T1, T3, T2;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
	       T3 = BYTWJ(&(W[TWVL * 14]), T2);
	       T4 = VADD(T1, T3);
	       TW = VSUB(T1, T3);
	       {
		    V T6, T8, T5, T7;
		    T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    T6 = BYTWJ(&(W[TWVL * 6]), T5);
		    T7 = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
		    T8 = BYTWJ(&(W[TWVL * 22]), T7);
		    T9 = VADD(T6, T8);
		    T19 = VSUB(T6, T8);
	       }
	       {
		    V TA, TH, TC, TF, TX, TY;
		    {
			 V Tz, TG, TB, TE;
			 Tz = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 TA = BYTWJ(&(W[TWVL * 26]), Tz);
			 TG = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			 TH = BYTWJ(&(W[TWVL * 18]), TG);
			 TB = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 TC = BYTWJ(&(W[TWVL * 10]), TB);
			 TE = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 TF = BYTWJ(&(W[TWVL * 2]), TE);
		    }
		    TD = VADD(TA, TC);
		    TI = VADD(TF, TH);
		    TX = VSUB(TF, TH);
		    TY = VSUB(TA, TC);
		    TZ = VADD(TX, TY);
		    T1a = VSUB(TY, TX);
	       }
	       {
		    V Tc, Tj, Te, Th, T11, T12;
		    {
			 V Tb, Ti, Td, Tg;
			 Tb = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 Tc = BYTWJ(&(W[0]), Tb);
			 Ti = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 Tj = BYTWJ(&(W[TWVL * 24]), Ti);
			 Td = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Te = BYTWJ(&(W[TWVL * 16]), Td);
			 Tg = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 Th = BYTWJ(&(W[TWVL * 8]), Tg);
		    }
		    Tf = VADD(Tc, Te);
		    Tk = VADD(Th, Tj);
		    Tl = VSUB(Tf, Tk);
		    T11 = VSUB(Tc, Te);
		    T12 = VSUB(Th, Tj);
		    T13 = VFNMS(LDK(KP414213562), T12, T11);
		    T1c = VFMA(LDK(KP414213562), T11, T12);
	       }
	       {
		    V Tn, Tu, Tp, Ts, T14, T15;
		    {
			 V Tm, Tt, To, Tr;
			 Tm = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
			 Tn = BYTWJ(&(W[TWVL * 28]), Tm);
			 Tt = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 Tu = BYTWJ(&(W[TWVL * 20]), Tt);
			 To = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Tp = BYTWJ(&(W[TWVL * 12]), To);
			 Tr = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Ts = BYTWJ(&(W[TWVL * 4]), Tr);
		    }
		    Tq = VADD(Tn, Tp);
		    Tv = VADD(Ts, Tu);
		    Tw = VSUB(Tq, Tv);
		    T14 = VSUB(Tn, Tp);
		    T15 = VSUB(Tu, Ts);
		    T16 = VFNMS(LDK(KP414213562), T15, T14);
		    T1d = VFMA(LDK(KP414213562), T14, T15);
	       }
	       {
		    V Ty, TM, TL, TN;
		    {
			 V Ta, Tx, TJ, TK;
			 Ta = VSUB(T4, T9);
			 Tx = VADD(Tl, Tw);
			 Ty = VFNMS(LDK(KP707106781), Tx, Ta);
			 TM = VFMA(LDK(KP707106781), Tx, Ta);
			 TJ = VSUB(TD, TI);
			 TK = VSUB(Tw, Tl);
			 TL = VFNMS(LDK(KP707106781), TK, TJ);
			 TN = VFMA(LDK(KP707106781), TK, TJ);
		    }
		    ST(&(x[WS(rs, 6)]), VFNMSI(TL, Ty), ms, &(x[0]));
		    ST(&(x[WS(rs, 2)]), VFMAI(TN, TM), ms, &(x[0]));
		    ST(&(x[WS(rs, 10)]), VFMAI(TL, Ty), ms, &(x[0]));
		    ST(&(x[WS(rs, 14)]), VFNMSI(TN, TM), ms, &(x[0]));
	       }
	       {
		    V T1k, T1o, T1n, T1p;
		    {
			 V T1i, T1j, T1l, T1m;
			 T1i = VFNMS(LDK(KP707106781), TZ, TW);
			 T1j = VADD(T1c, T1d);
			 T1k = VFNMS(LDK(KP923879532), T1j, T1i);
			 T1o = VFMA(LDK(KP923879532), T1j, T1i);
			 T1l = VFMA(LDK(KP707106781), T1a, T19);
			 T1m = VSUB(T16, T13);
			 T1n = VFNMS(LDK(KP923879532), T1m, T1l);
			 T1p = VFMA(LDK(KP923879532), T1m, T1l);
		    }
		    ST(&(x[WS(rs, 5)]), VFNMSI(T1n, T1k), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 13)]), VFNMSI(T1p, T1o), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 11)]), VFMAI(T1n, T1k), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 3)]), VFMAI(T1p, T1o), ms, &(x[WS(rs, 1)]));
	       }
	       {
		    V TQ, TU, TT, TV;
		    {
			 V TO, TP, TR, TS;
			 TO = VADD(T4, T9);
			 TP = VADD(TI, TD);
			 TQ = VADD(TO, TP);
			 TU = VSUB(TO, TP);
			 TR = VADD(Tf, Tk);
			 TS = VADD(Tq, Tv);
			 TT = VADD(TR, TS);
			 TV = VSUB(TS, TR);
		    }
		    ST(&(x[WS(rs, 8)]), VSUB(TQ, TT), ms, &(x[0]));
		    ST(&(x[WS(rs, 4)]), VFMAI(TV, TU), ms, &(x[0]));
		    ST(&(x[0]), VADD(TQ, TT), ms, &(x[0]));
		    ST(&(x[WS(rs, 12)]), VFNMSI(TV, TU), ms, &(x[0]));
	       }
	       {
		    V T18, T1g, T1f, T1h;
		    {
			 V T10, T17, T1b, T1e;
			 T10 = VFMA(LDK(KP707106781), TZ, TW);
			 T17 = VADD(T13, T16);
			 T18 = VFNMS(LDK(KP923879532), T17, T10);
			 T1g = VFMA(LDK(KP923879532), T17, T10);
			 T1b = VFNMS(LDK(KP707106781), T1a, T19);
			 T1e = VSUB(T1c, T1d);
			 T1f = VFNMS(LDK(KP923879532), T1e, T1b);
			 T1h = VFMA(LDK(KP923879532), T1e, T1b);
		    }
		    ST(&(x[WS(rs, 9)]), VFNMSI(T1f, T18), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 15)]), VFMAI(T1h, T1g), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 7)]), VFMAI(T1f, T18), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 1)]), VFNMSI(T1h, T1g), ms, &(x[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t1fv_16"), twinstr, &GENUS, {53, 30, 34, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fv_16) (planner *p) {
     X(kdft_dit_register) (p, t1fv_16, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 16 -name t1fv_16 -include dft/simd/t1f.h */

/*
 * This function contains 87 FP additions, 42 FP multiplications,
 * (or, 83 additions, 38 multiplications, 4 fused multiply/add),
 * 36 stack variables, 3 constants, and 32 memory accesses
 */
#include "dft/simd/t1f.h"

static void t1fv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 30)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 30), MAKE_VOLATILE_STRIDE(16, rs)) {
	       V TJ, T10, TD, T11, T1b, T1c, Ty, TK, T16, T17, T18, Tb, TN, T13, T14;
	       V T15, Tm, TM, TG, TI, TH;
	       TG = LD(&(x[0]), ms, &(x[0]));
	       TH = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
	       TI = BYTWJ(&(W[TWVL * 14]), TH);
	       TJ = VSUB(TG, TI);
	       T10 = VADD(TG, TI);
	       {
		    V TA, TC, Tz, TB;
		    Tz = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    TA = BYTWJ(&(W[TWVL * 6]), Tz);
		    TB = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
		    TC = BYTWJ(&(W[TWVL * 22]), TB);
		    TD = VSUB(TA, TC);
		    T11 = VADD(TA, TC);
	       }
	       {
		    V Tp, Tw, Tr, Tu, Ts, Tx;
		    {
			 V To, Tv, Tq, Tt;
			 To = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 Tp = BYTWJ(&(W[TWVL * 26]), To);
			 Tv = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			 Tw = BYTWJ(&(W[TWVL * 18]), Tv);
			 Tq = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tr = BYTWJ(&(W[TWVL * 10]), Tq);
			 Tt = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 Tu = BYTWJ(&(W[TWVL * 2]), Tt);
		    }
		    T1b = VADD(Tp, Tr);
		    T1c = VADD(Tu, Tw);
		    Ts = VSUB(Tp, Tr);
		    Tx = VSUB(Tu, Tw);
		    Ty = VMUL(LDK(KP707106781), VSUB(Ts, Tx));
		    TK = VMUL(LDK(KP707106781), VADD(Tx, Ts));
	       }
	       {
		    V T2, T9, T4, T7, T5, Ta;
		    {
			 V T1, T8, T3, T6;
			 T1 = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
			 T2 = BYTWJ(&(W[TWVL * 28]), T1);
			 T8 = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 T9 = BYTWJ(&(W[TWVL * 20]), T8);
			 T3 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 T4 = BYTWJ(&(W[TWVL * 12]), T3);
			 T6 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 T7 = BYTWJ(&(W[TWVL * 4]), T6);
		    }
		    T16 = VADD(T2, T4);
		    T17 = VADD(T7, T9);
		    T18 = VSUB(T16, T17);
		    T5 = VSUB(T2, T4);
		    Ta = VSUB(T7, T9);
		    Tb = VFNMS(LDK(KP923879532), Ta, VMUL(LDK(KP382683432), T5));
		    TN = VFMA(LDK(KP923879532), T5, VMUL(LDK(KP382683432), Ta));
	       }
	       {
		    V Td, Tk, Tf, Ti, Tg, Tl;
		    {
			 V Tc, Tj, Te, Th;
			 Tc = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 Td = BYTWJ(&(W[0]), Tc);
			 Tj = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 Tk = BYTWJ(&(W[TWVL * 24]), Tj);
			 Te = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tf = BYTWJ(&(W[TWVL * 16]), Te);
			 Th = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 Ti = BYTWJ(&(W[TWVL * 8]), Th);
		    }
		    T13 = VADD(Td, Tf);
		    T14 = VADD(Ti, Tk);
		    T15 = VSUB(T13, T14);
		    Tg = VSUB(Td, Tf);
		    Tl = VSUB(Ti, Tk);
		    Tm = VFMA(LDK(KP382683432), Tg, VMUL(LDK(KP923879532), Tl));
		    TM = VFNMS(LDK(KP382683432), Tl, VMUL(LDK(KP923879532), Tg));
	       }
	       {
		    V T1a, T1g, T1f, T1h;
		    {
			 V T12, T19, T1d, T1e;
			 T12 = VSUB(T10, T11);
			 T19 = VMUL(LDK(KP707106781), VADD(T15, T18));
			 T1a = VADD(T12, T19);
			 T1g = VSUB(T12, T19);
			 T1d = VSUB(T1b, T1c);
			 T1e = VMUL(LDK(KP707106781), VSUB(T18, T15));
			 T1f = VBYI(VADD(T1d, T1e));
			 T1h = VBYI(VSUB(T1e, T1d));
		    }
		    ST(&(x[WS(rs, 14)]), VSUB(T1a, T1f), ms, &(x[0]));
		    ST(&(x[WS(rs, 6)]), VADD(T1g, T1h), ms, &(x[0]));
		    ST(&(x[WS(rs, 2)]), VADD(T1a, T1f), ms, &(x[0]));
		    ST(&(x[WS(rs, 10)]), VSUB(T1g, T1h), ms, &(x[0]));
	       }
	       {
		    V T1k, T1o, T1n, T1p;
		    {
			 V T1i, T1j, T1l, T1m;
			 T1i = VADD(T10, T11);
			 T1j = VADD(T1c, T1b);
			 T1k = VADD(T1i, T1j);
			 T1o = VSUB(T1i, T1j);
			 T1l = VADD(T13, T14);
			 T1m = VADD(T16, T17);
			 T1n = VADD(T1l, T1m);
			 T1p = VBYI(VSUB(T1m, T1l));
		    }
		    ST(&(x[WS(rs, 8)]), VSUB(T1k, T1n), ms, &(x[0]));
		    ST(&(x[WS(rs, 4)]), VADD(T1o, T1p), ms, &(x[0]));
		    ST(&(x[0]), VADD(T1k, T1n), ms, &(x[0]));
		    ST(&(x[WS(rs, 12)]), VSUB(T1o, T1p), ms, &(x[0]));
	       }
	       {
		    V TF, TQ, TP, TR;
		    {
			 V Tn, TE, TL, TO;
			 Tn = VSUB(Tb, Tm);
			 TE = VSUB(Ty, TD);
			 TF = VBYI(VSUB(Tn, TE));
			 TQ = VBYI(VADD(TE, Tn));
			 TL = VADD(TJ, TK);
			 TO = VADD(TM, TN);
			 TP = VSUB(TL, TO);
			 TR = VADD(TL, TO);
		    }
		    ST(&(x[WS(rs, 7)]), VADD(TF, TP), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 15)]), VSUB(TR, TQ), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 9)]), VSUB(TP, TF), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 1)]), VADD(TQ, TR), ms, &(x[WS(rs, 1)]));
	       }
	       {
		    V TU, TY, TX, TZ;
		    {
			 V TS, TT, TV, TW;
			 TS = VSUB(TJ, TK);
			 TT = VADD(Tm, Tb);
			 TU = VADD(TS, TT);
			 TY = VSUB(TS, TT);
			 TV = VADD(TD, Ty);
			 TW = VSUB(TN, TM);
			 TX = VBYI(VADD(TV, TW));
			 TZ = VBYI(VSUB(TW, TV));
		    }
		    ST(&(x[WS(rs, 13)]), VSUB(TU, TX), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 5)]), VADD(TY, TZ), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 3)]), VADD(TU, TX), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 11)]), VSUB(TY, TZ), ms, &(x[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t1fv_16"), twinstr, &GENUS, {83, 38, 4, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fv_16) (planner *p) {
     X(kdft_dit_register) (p, t1fv_16, &desc);
}
#endif
