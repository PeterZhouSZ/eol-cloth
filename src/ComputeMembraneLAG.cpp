#include <cmath>
void ComputeMembraneLAG(
   const double *xa, // [input 3x1] World position of vertex A
   const double *xb, // [input 3x1] World position of vertex B
   const double *xc, // [input 3x1] World position of vertex C
   const double *Xa, // [input 2x1] Material position of vertex A
   const double *Xb, // [input 2x1] Material position of vertex B
   const double *Xc, // [input 2x1] Material position of vertex C
   double e,         // [input 1x1] Young's modulus -pascals
   double nu,        // [input 1x1] Poisson's ratio 0.3 or 0.2
   const double *P,  // [input 2x3] Projection matrix (column major)
   const double *Q,  // [input 2x2] Polar decomposition of \bar{F} (column major)
   double *W,        // [output 1x1] Membrane potential energy
   double *f,        // [output 9x1] Membrane force vector
   double *K)        // [output 9x9] Membrane stiffness matrix
{
double xax = xa[0];
double xay = xa[1];
double xaz = xa[2];
double xbx = xb[0];
double xby = xb[1];
double xbz = xb[2];
double xcx = xc[0];
double xcy = xc[1];
double xcz = xc[2];
double Xax = Xa[0];
double Xay = Xa[1];
double Xbx = Xb[0];
double Xby = Xb[1];
double Xcx = Xc[0];
double Xcy = Xc[1];
// P and Q are stored as column-major matrices
double P00 = P[0];
double P10 = P[1];
double P01 = P[2];
double P11 = P[3];
double P02 = P[4];
double P12 = P[5];
double Q00 = Q[0];
double Q10 = Q[1];
double Q01 = Q[2];
double Q11 = Q[3];
double t7 = Xax * Xby - Xax * Xcy - Xbx * Xay + Xcx * Xay + Xbx * Xcy - Xcx * Xby;
double t8 = t7 / 2;
double t9 = 1 + nu;
double t12 = e / t9 / 2;
double t15 = P00 * Q00 + P10 * Q10;
double t17 = 0.1e1 / t7;
double t18 = (xbx - xax) * t17;
double t19 = Xcy - Xay;
double t22 = (xcx - xax) * t17;
double t23 = -Xby + Xay;
double t25 = t18 * t19 + t22 * t23;
double t26 = t15 * t25;
double t29 = P01 * Q00 + P11 * Q10;
double t31 = (xby - xay) * t17;
double t34 = (xcy - xay) * t17;
double t36 = t31 * t19 + t34 * t23;
double t37 = t29 * t36;
double t40 = P02 * Q00 + P12 * Q10;
double t42 = (xbz - xaz) * t17;
double t45 = (xcz - xaz) * t17;
double t47 = t42 * t19 + t45 * t23;
double t48 = t40 * t47;
double t49 = t26 + t37 + t48 - 1;
double t50 = t49 * t49;
double t53 = P00 * Q01 + P10 * Q11;
double t57 = P01 * Q01 + P11 * Q11;
double t61 = P02 * Q01 + P12 * Q11;
double t63 = t53 * t25 + t57 * t36 + t61 * t47;
double t64 = t63 * t63;
double t65 = -Xcx + Xax;
double t67 = Xbx - Xax;
double t69 = t18 * t65 + t22 * t67;
double t73 = t31 * t65 + t34 * t67;
double t77 = t42 * t65 + t45 * t67;
double t79 = t15 * t69 + t29 * t73 + t40 * t77;
double t80 = t79 * t79;
double t81 = t53 * t69;
double t82 = t57 * t73;
double t83 = t61 * t77;
double t84 = t81 + t82 + t83 - 1;
double t85 = t84 * t84;
double t88 = e * nu;
double t89 = 1 / t9;
double t92 = 1 / (1 - 2 * nu);
double t93 = t89 * t92;
double t94 = t26 + t37 + t48 - 2 + t81 + t82 + t83;
double t95 = t94 * t94;
double W00 = t8 * (t12 * (t50 + t64 + t80 + t85) + t88 * t93 * t95 / 2);
double t100 = t49 * t15;
double t101 = t17 * t19;
double t102 = t17 * t23;
double t103 = -t101 - t102;
double t105 = t63 * t53;
double t107 = t79 * t15;
double t108 = t17 * t65;
double t109 = t17 * t67;
double t110 = -t108 - t109;
double t112 = t84 * t53;
double t117 = t88 * t89;
double t118 = t92 * t94;
double t121 = t15 * t103 + t53 * t110;
double f01 = -t8 * (t12 * (2 * t100 * t103 + 2 * t105 * t103 + 2 * t107 * t110 + 2 * t112 * t110) + t117 * t118 * t121);
double t126 = t49 * t29;
double t128 = t63 * t57;
double t130 = t79 * t29;
double t132 = t84 * t57;
double t139 = t29 * t103 + t57 * t110;
double f02 = -t8 * (t12 * (2 * t126 * t103 + 2 * t128 * t103 + 2 * t130 * t110 + 2 * t132 * t110) + t117 * t118 * t139);
double t144 = t49 * t40;
double t146 = t63 * t61;
double t148 = t79 * t40;
double t150 = t84 * t61;
double t157 = t40 * t103 + t61 * t110;
double f03 = -t8 * (t12 * (2 * t144 * t103 + 2 * t146 * t103 + 2 * t148 * t110 + 2 * t150 * t110) + t117 * t118 * t157);
double t169 = t15 * t17;
double t171 = t53 * t17;
double t173 = t169 * t19 + t171 * t65;
double f04 = -t8 * (t12 * (2 * t100 * t101 + 2 * t105 * t101 + 2 * t107 * t108 + 2 * t112 * t108) + t117 * t118 * t173);
double t185 = t29 * t17;
double t187 = t57 * t17;
double t189 = t185 * t19 + t187 * t65;
double f05 = -t8 * (t12 * (2 * t126 * t101 + 2 * t128 * t101 + 2 * t130 * t108 + 2 * t132 * t108) + t117 * t118 * t189);
double t201 = t40 * t17;
double t203 = t61 * t17;
double t205 = t201 * t19 + t203 * t65;
double f06 = -t8 * (t12 * (2 * t144 * t101 + 2 * t146 * t101 + 2 * t148 * t108 + 2 * t150 * t108) + t117 * t118 * t205);
double t219 = t169 * t23 + t171 * t67;
double f07 = -t8 * (t12 * (2 * t100 * t102 + 2 * t105 * t102 + 2 * t107 * t109 + 2 * t112 * t109) + t117 * t118 * t219);
double t233 = t185 * t23 + t187 * t67;
double f08 = -t8 * (t12 * (2 * t126 * t102 + 2 * t128 * t102 + 2 * t130 * t109 + 2 * t132 * t109) + t117 * t118 * t233);
double t247 = t201 * t23 + t203 * t67;
double f09 = -t8 * (t12 * (2 * t144 * t102 + 2 * t146 * t102 + 2 * t148 * t109 + 2 * t150 * t109) + t117 * t118 * t247);
double t252 = t15 * t15;
double t253 = t103 * t103;
double t255 = t53 * t53;
double t257 = t110 * t110;
double t263 = t121 * t121;
double K0101 = t8 * (t12 * (2 * t252 * t253 + 2 * t252 * t257 + 2 * t255 * t253 + 2 * t255 * t257) + t88 * t93 * t263);
double K0102 = t8 * (t12 * (2 * t29 * t253 * t15 + 2 * t29 * t257 * t15 + 2 * t57 * t253 * t53 + 2 * t57 * t257 * t53) + t117 * t92 * t139 * t121);
double t282 = t40 * t253;
double t284 = t61 * t253;
double t286 = t40 * t257;
double t288 = t61 * t257;
double t293 = t92 * t157;
double K0103 = t8 * (t12 * (2 * t282 * t15 + 2 * t286 * t15 + 2 * t284 * t53 + 2 * t288 * t53) + t117 * t293 * t121);
double t297 = t252 * t17;
double t298 = t19 * t103;
double t300 = t255 * t17;
double t302 = t65 * t110;
double t308 = t92 * t173;
double K0104 = t8 * (t12 * (2 * t297 * t298 + 2 * t297 * t302 + 2 * t300 * t298 + 2 * t300 * t302) + t117 * t308 * t121);
double t313 = t19 * t15 * t103;
double t316 = t19 * t53 * t103;
double t319 = t65 * t15 * t110;
double t322 = t65 * t53 * t110;
double t326 = t12 * (2 * t185 * t313 + 2 * t185 * t319 + 2 * t187 * t316 + 2 * t187 * t322);
double t327 = t92 * t189;
double K0105 = t8 * (t117 * t327 * t121 + t326);
double t337 = t12 * (2 * t201 * t313 + 2 * t201 * t319 + 2 * t203 * t316 + 2 * t203 * t322);
double t338 = t92 * t205;
double K0106 = t8 * (t117 * t338 * t121 + t337);
double t342 = t23 * t103;
double t345 = t67 * t110;
double t351 = t92 * t219;
double K0107 = t8 * (t12 * (2 * t297 * t342 + 2 * t297 * t345 + 2 * t300 * t342 + 2 * t300 * t345) + t117 * t351 * t121);
double t355 = t23 * t15;
double t356 = t355 * t103;
double t358 = t23 * t53;
double t359 = t358 * t103;
double t361 = t67 * t15;
double t362 = t361 * t110;
double t364 = t67 * t53;
double t365 = t364 * t110;
double t369 = t12 * (2 * t185 * t356 + 2 * t185 * t362 + 2 * t187 * t359 + 2 * t187 * t365);
double t370 = t92 * t233;
double K0108 = t8 * (t117 * t370 * t121 + t369);
double t380 = t12 * (2 * t201 * t356 + 2 * t201 * t362 + 2 * t203 * t359 + 2 * t203 * t365);
double t381 = t92 * t247;
double K0109 = t8 * (t117 * t381 * t121 + t380);
double K0201 = K0102;
double t385 = t29 * t29;
double t387 = t57 * t57;
double t394 = t139 * t139;
double K0202 = t8 * (t12 * (2 * t385 * t253 + 2 * t387 * t253 + 2 * t385 * t257 + 2 * t387 * t257) + t88 * t93 * t394);
double K0203 = t8 * (t12 * (2 * t282 * t29 + 2 * t284 * t57 + 2 * t286 * t29 + 2 * t288 * t57) + t117 * t293 * t139);
double K0204 = t8 * (t117 * t308 * t139 + t326);
double t411 = t385 * t17;
double t413 = t387 * t17;
double K0205 = t8 * (t12 * (2 * t411 * t298 + 2 * t413 * t298 + 2 * t411 * t302 + 2 * t413 * t302) + t117 * t327 * t139);
double t437 = t12 * (2 * t201 * t19 * t29 * t103 + 2 * t203 * t19 * t57 * t103 + 2 * t201 * t65 * t29 * t110 + 2 * t203 * t65 * t57 * t110);
double K0206 = t8 * (t117 * t338 * t139 + t437);
double K0207 = t8 * (t117 * t351 * t139 + t369);
double K0208 = t8 * (t12 * (2 * t411 * t342 + 2 * t413 * t342 + 2 * t411 * t345 + 2 * t413 * t345) + t117 * t370 * t139);
double t454 = t23 * t29;
double t457 = t23 * t57;
double t460 = t67 * t29;
double t463 = t67 * t57;
double t468 = t12 * (2 * t201 * t454 * t103 + 2 * t203 * t457 * t103 + 2 * t201 * t460 * t110 + 2 * t203 * t463 * t110);
double K0209 = t8 * (t117 * t381 * t139 + t468);
double K0301 = K0103;
double K0302 = K0203;
double t472 = t40 * t40;
double t474 = t61 * t61;
double t481 = t157 * t157;
double K0303 = t8 * (t12 * (2 * t472 * t253 + 2 * t474 * t253 + 2 * t472 * t257 + 2 * t474 * t257) + t88 * t93 * t481);
double K0304 = t8 * (t117 * t308 * t157 + t337);
double K0305 = t8 * (t117 * t327 * t157 + t437);
double t491 = t472 * t17;
double t493 = t474 * t17;
double K0306 = t8 * (t12 * (2 * t491 * t298 + 2 * t493 * t298 + 2 * t491 * t302 + 2 * t493 * t302) + t117 * t338 * t157);
double K0307 = t8 * (t117 * t351 * t157 + t380);
double K0308 = t8 * (t117 * t370 * t157 + t468);
double K0309 = t8 * (t12 * (2 * t491 * t342 + 2 * t493 * t342 + 2 * t491 * t345 + 2 * t493 * t345) + t117 * t381 * t157);
double K0401 = K0104;
double K0402 = K0204;
double K0403 = K0304;
double t519 = t7 * t7;
double t520 = 0.1e1 / t519;
double t521 = t252 * t520;
double t522 = t19 * t19;
double t524 = t255 * t520;
double t526 = t65 * t65;
double t532 = t173 * t173;
double K0404 = t8 * (t12 * (2 * t521 * t522 + 2 * t521 * t526 + 2 * t524 * t522 + 2 * t524 * t526) + t88 * t93 * t532);
double t536 = t29 * t520;
double t537 = t522 * t15;
double t539 = t57 * t520;
double t540 = t522 * t53;
double t542 = t526 * t15;
double t544 = t526 * t53;
double K0405 = t8 * (t12 * (2 * t536 * t537 + 2 * t536 * t542 + 2 * t539 * t540 + 2 * t539 * t544) + t117 * t327 * t173);
double t552 = t40 * t520;
double t554 = t61 * t520;
double K0406 = t8 * (t12 * (2 * t552 * t537 + 2 * t554 * t540 + 2 * t552 * t542 + 2 * t554 * t544) + t117 * t338 * t173);
double t564 = t23 * t19;
double t567 = t67 * t65;
double K0407 = t8 * (t12 * (2 * t521 * t564 + 2 * t521 * t567 + 2 * t524 * t564 + 2 * t524 * t567) + t117 * t351 * t173);
double t576 = t355 * t19;
double t578 = t358 * t19;
double t580 = t361 * t65;
double t582 = t364 * t65;
double t586 = t12 * (2 * t536 * t576 + 2 * t536 * t580 + 2 * t539 * t578 + 2 * t539 * t582);
double K0408 = t8 * (t117 * t370 * t173 + t586);
double t596 = t12 * (2 * t552 * t576 + 2 * t552 * t580 + 2 * t554 * t578 + 2 * t554 * t582);
double K0409 = t8 * (t117 * t381 * t173 + t596);
double K0501 = K0105;
double K0502 = K0205;
double K0503 = K0305;
double K0504 = K0405;
double t600 = t385 * t520;
double t602 = t387 * t520;
double t609 = t189 * t189;
double K0505 = t8 * (t12 * (2 * t600 * t522 + 2 * t602 * t522 + 2 * t600 * t526 + 2 * t602 * t526) + t88 * t93 * t609);
double K0506 = t8 * (t12 * (2 * t552 * t522 * t29 + 2 * t552 * t526 * t29 + 2 * t554 * t522 * t57 + 2 * t554 * t526 * t57) + t117 * t338 * t189);
double K0507 = t8 * (t117 * t351 * t189 + t586);
double K0508 = t8 * (t12 * (2 * t600 * t564 + 2 * t602 * t564 + 2 * t600 * t567 + 2 * t602 * t567) + t117 * t370 * t189);
double t650 = t12 * (2 * t552 * t454 * t19 + 2 * t554 * t457 * t19 + 2 * t552 * t460 * t65 + 2 * t554 * t463 * t65);
double K0509 = t8 * (t117 * t381 * t189 + t650);
double K0601 = K0106;
double K0602 = K0206;
double K0603 = K0306;
double K0604 = K0406;
double K0605 = K0506;
double t654 = t472 * t520;
double t656 = t474 * t520;
double t663 = t205 * t205;
double K0606 = t8 * (t12 * (2 * t654 * t522 + 2 * t656 * t522 + 2 * t654 * t526 + 2 * t656 * t526) + t88 * t93 * t663);
double K0607 = t8 * (t117 * t351 * t205 + t596);
double K0608 = t8 * (t117 * t370 * t205 + t650);
double K0609 = t8 * (t12 * (2 * t654 * t564 + 2 * t656 * t564 + 2 * t654 * t567 + 2 * t656 * t567) + t117 * t381 * t205);
double K0701 = K0107;
double K0702 = K0207;
double K0703 = K0307;
double K0704 = K0407;
double K0705 = K0507;
double K0706 = K0607;
double t683 = t23 * t23;
double t686 = t67 * t67;
double t692 = t219 * t219;
double K0707 = t8 * (t12 * (2 * t521 * t683 + 2 * t521 * t686 + 2 * t524 * t683 + 2 * t524 * t686) + t88 * t93 * t692);
double t696 = t683 * t15;
double t698 = t683 * t53;
double t700 = t686 * t15;
double t702 = t686 * t53;
double K0708 = t8 * (t12 * (2 * t536 * t696 + 2 * t536 * t700 + 2 * t539 * t698 + 2 * t539 * t702) + t117 * t370 * t219);
double K0709 = t8 * (t12 * (2 * t552 * t696 + 2 * t552 * t700 + 2 * t554 * t698 + 2 * t554 * t702) + t117 * t381 * t219);
double K0801 = K0108;
double K0802 = K0208;
double K0803 = K0308;
double K0804 = K0408;
double K0805 = K0508;
double K0806 = K0608;
double K0807 = K0708;
double t727 = t233 * t233;
double K0808 = t8 * (t12 * (2 * t600 * t683 + 2 * t600 * t686 + 2 * t602 * t683 + 2 * t602 * t686) + t88 * t93 * t727);
double K0809 = t8 * (t12 * (2 * t552 * t683 * t29 + 2 * t552 * t686 * t29 + 2 * t554 * t683 * t57 + 2 * t554 * t686 * t57) + t117 * t381 * t233);
double K0901 = K0109;
double K0902 = K0209;
double K0903 = K0309;
double K0904 = K0409;
double K0905 = K0509;
double K0906 = K0609;
double K0907 = K0709;
double K0908 = K0809;
double t752 = t247 * t247;
double K0909 = t8 * (t12 * (2 * t654 * t683 + 2 * t654 * t686 + 2 * t656 * t683 + 2 * t656 * t686) + t88 * t93 * t752);
W[0]=W00;
f[0]=f01; f[1]=f02; f[2]=f03; f[3]=f04; f[4]=f05; f[5]=f06; f[6]=f07; f[7]=f08; f[8]=f09; 
K[ 0*9+ 0]=K0101; K[ 0*9+ 1]=K0102; K[ 0*9+ 2]=K0103; K[ 0*9+ 3]=K0104; K[ 0*9+ 4]=K0105; K[ 0*9+ 5]=K0106; K[ 0*9+ 6]=K0107; K[ 0*9+ 7]=K0108; K[ 0*9+ 8]=K0109; 
K[ 1*9+ 0]=K0201; K[ 1*9+ 1]=K0202; K[ 1*9+ 2]=K0203; K[ 1*9+ 3]=K0204; K[ 1*9+ 4]=K0205; K[ 1*9+ 5]=K0206; K[ 1*9+ 6]=K0207; K[ 1*9+ 7]=K0208; K[ 1*9+ 8]=K0209; 
K[ 2*9+ 0]=K0301; K[ 2*9+ 1]=K0302; K[ 2*9+ 2]=K0303; K[ 2*9+ 3]=K0304; K[ 2*9+ 4]=K0305; K[ 2*9+ 5]=K0306; K[ 2*9+ 6]=K0307; K[ 2*9+ 7]=K0308; K[ 2*9+ 8]=K0309; 
K[ 3*9+ 0]=K0401; K[ 3*9+ 1]=K0402; K[ 3*9+ 2]=K0403; K[ 3*9+ 3]=K0404; K[ 3*9+ 4]=K0405; K[ 3*9+ 5]=K0406; K[ 3*9+ 6]=K0407; K[ 3*9+ 7]=K0408; K[ 3*9+ 8]=K0409; 
K[ 4*9+ 0]=K0501; K[ 4*9+ 1]=K0502; K[ 4*9+ 2]=K0503; K[ 4*9+ 3]=K0504; K[ 4*9+ 4]=K0505; K[ 4*9+ 5]=K0506; K[ 4*9+ 6]=K0507; K[ 4*9+ 7]=K0508; K[ 4*9+ 8]=K0509; 
K[ 5*9+ 0]=K0601; K[ 5*9+ 1]=K0602; K[ 5*9+ 2]=K0603; K[ 5*9+ 3]=K0604; K[ 5*9+ 4]=K0605; K[ 5*9+ 5]=K0606; K[ 5*9+ 6]=K0607; K[ 5*9+ 7]=K0608; K[ 5*9+ 8]=K0609; 
K[ 6*9+ 0]=K0701; K[ 6*9+ 1]=K0702; K[ 6*9+ 2]=K0703; K[ 6*9+ 3]=K0704; K[ 6*9+ 4]=K0705; K[ 6*9+ 5]=K0706; K[ 6*9+ 6]=K0707; K[ 6*9+ 7]=K0708; K[ 6*9+ 8]=K0709; 
K[ 7*9+ 0]=K0801; K[ 7*9+ 1]=K0802; K[ 7*9+ 2]=K0803; K[ 7*9+ 3]=K0804; K[ 7*9+ 4]=K0805; K[ 7*9+ 5]=K0806; K[ 7*9+ 6]=K0807; K[ 7*9+ 7]=K0808; K[ 7*9+ 8]=K0809; 
K[ 8*9+ 0]=K0901; K[ 8*9+ 1]=K0902; K[ 8*9+ 2]=K0903; K[ 8*9+ 3]=K0904; K[ 8*9+ 4]=K0905; K[ 8*9+ 5]=K0906; K[ 8*9+ 6]=K0907; K[ 8*9+ 7]=K0908; K[ 8*9+ 8]=K0909; 
}