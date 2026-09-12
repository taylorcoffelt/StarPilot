#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2603305221510379343) {
   out_2603305221510379343[0] = delta_x[0] + nom_x[0];
   out_2603305221510379343[1] = delta_x[1] + nom_x[1];
   out_2603305221510379343[2] = delta_x[2] + nom_x[2];
   out_2603305221510379343[3] = delta_x[3] + nom_x[3];
   out_2603305221510379343[4] = delta_x[4] + nom_x[4];
   out_2603305221510379343[5] = delta_x[5] + nom_x[5];
   out_2603305221510379343[6] = delta_x[6] + nom_x[6];
   out_2603305221510379343[7] = delta_x[7] + nom_x[7];
   out_2603305221510379343[8] = delta_x[8] + nom_x[8];
   out_2603305221510379343[9] = delta_x[9] + nom_x[9];
   out_2603305221510379343[10] = delta_x[10] + nom_x[10];
   out_2603305221510379343[11] = delta_x[11] + nom_x[11];
   out_2603305221510379343[12] = delta_x[12] + nom_x[12];
   out_2603305221510379343[13] = delta_x[13] + nom_x[13];
   out_2603305221510379343[14] = delta_x[14] + nom_x[14];
   out_2603305221510379343[15] = delta_x[15] + nom_x[15];
   out_2603305221510379343[16] = delta_x[16] + nom_x[16];
   out_2603305221510379343[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4906336809504339286) {
   out_4906336809504339286[0] = -nom_x[0] + true_x[0];
   out_4906336809504339286[1] = -nom_x[1] + true_x[1];
   out_4906336809504339286[2] = -nom_x[2] + true_x[2];
   out_4906336809504339286[3] = -nom_x[3] + true_x[3];
   out_4906336809504339286[4] = -nom_x[4] + true_x[4];
   out_4906336809504339286[5] = -nom_x[5] + true_x[5];
   out_4906336809504339286[6] = -nom_x[6] + true_x[6];
   out_4906336809504339286[7] = -nom_x[7] + true_x[7];
   out_4906336809504339286[8] = -nom_x[8] + true_x[8];
   out_4906336809504339286[9] = -nom_x[9] + true_x[9];
   out_4906336809504339286[10] = -nom_x[10] + true_x[10];
   out_4906336809504339286[11] = -nom_x[11] + true_x[11];
   out_4906336809504339286[12] = -nom_x[12] + true_x[12];
   out_4906336809504339286[13] = -nom_x[13] + true_x[13];
   out_4906336809504339286[14] = -nom_x[14] + true_x[14];
   out_4906336809504339286[15] = -nom_x[15] + true_x[15];
   out_4906336809504339286[16] = -nom_x[16] + true_x[16];
   out_4906336809504339286[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5030482369160908110) {
   out_5030482369160908110[0] = 1.0;
   out_5030482369160908110[1] = 0.0;
   out_5030482369160908110[2] = 0.0;
   out_5030482369160908110[3] = 0.0;
   out_5030482369160908110[4] = 0.0;
   out_5030482369160908110[5] = 0.0;
   out_5030482369160908110[6] = 0.0;
   out_5030482369160908110[7] = 0.0;
   out_5030482369160908110[8] = 0.0;
   out_5030482369160908110[9] = 0.0;
   out_5030482369160908110[10] = 0.0;
   out_5030482369160908110[11] = 0.0;
   out_5030482369160908110[12] = 0.0;
   out_5030482369160908110[13] = 0.0;
   out_5030482369160908110[14] = 0.0;
   out_5030482369160908110[15] = 0.0;
   out_5030482369160908110[16] = 0.0;
   out_5030482369160908110[17] = 0.0;
   out_5030482369160908110[18] = 0.0;
   out_5030482369160908110[19] = 1.0;
   out_5030482369160908110[20] = 0.0;
   out_5030482369160908110[21] = 0.0;
   out_5030482369160908110[22] = 0.0;
   out_5030482369160908110[23] = 0.0;
   out_5030482369160908110[24] = 0.0;
   out_5030482369160908110[25] = 0.0;
   out_5030482369160908110[26] = 0.0;
   out_5030482369160908110[27] = 0.0;
   out_5030482369160908110[28] = 0.0;
   out_5030482369160908110[29] = 0.0;
   out_5030482369160908110[30] = 0.0;
   out_5030482369160908110[31] = 0.0;
   out_5030482369160908110[32] = 0.0;
   out_5030482369160908110[33] = 0.0;
   out_5030482369160908110[34] = 0.0;
   out_5030482369160908110[35] = 0.0;
   out_5030482369160908110[36] = 0.0;
   out_5030482369160908110[37] = 0.0;
   out_5030482369160908110[38] = 1.0;
   out_5030482369160908110[39] = 0.0;
   out_5030482369160908110[40] = 0.0;
   out_5030482369160908110[41] = 0.0;
   out_5030482369160908110[42] = 0.0;
   out_5030482369160908110[43] = 0.0;
   out_5030482369160908110[44] = 0.0;
   out_5030482369160908110[45] = 0.0;
   out_5030482369160908110[46] = 0.0;
   out_5030482369160908110[47] = 0.0;
   out_5030482369160908110[48] = 0.0;
   out_5030482369160908110[49] = 0.0;
   out_5030482369160908110[50] = 0.0;
   out_5030482369160908110[51] = 0.0;
   out_5030482369160908110[52] = 0.0;
   out_5030482369160908110[53] = 0.0;
   out_5030482369160908110[54] = 0.0;
   out_5030482369160908110[55] = 0.0;
   out_5030482369160908110[56] = 0.0;
   out_5030482369160908110[57] = 1.0;
   out_5030482369160908110[58] = 0.0;
   out_5030482369160908110[59] = 0.0;
   out_5030482369160908110[60] = 0.0;
   out_5030482369160908110[61] = 0.0;
   out_5030482369160908110[62] = 0.0;
   out_5030482369160908110[63] = 0.0;
   out_5030482369160908110[64] = 0.0;
   out_5030482369160908110[65] = 0.0;
   out_5030482369160908110[66] = 0.0;
   out_5030482369160908110[67] = 0.0;
   out_5030482369160908110[68] = 0.0;
   out_5030482369160908110[69] = 0.0;
   out_5030482369160908110[70] = 0.0;
   out_5030482369160908110[71] = 0.0;
   out_5030482369160908110[72] = 0.0;
   out_5030482369160908110[73] = 0.0;
   out_5030482369160908110[74] = 0.0;
   out_5030482369160908110[75] = 0.0;
   out_5030482369160908110[76] = 1.0;
   out_5030482369160908110[77] = 0.0;
   out_5030482369160908110[78] = 0.0;
   out_5030482369160908110[79] = 0.0;
   out_5030482369160908110[80] = 0.0;
   out_5030482369160908110[81] = 0.0;
   out_5030482369160908110[82] = 0.0;
   out_5030482369160908110[83] = 0.0;
   out_5030482369160908110[84] = 0.0;
   out_5030482369160908110[85] = 0.0;
   out_5030482369160908110[86] = 0.0;
   out_5030482369160908110[87] = 0.0;
   out_5030482369160908110[88] = 0.0;
   out_5030482369160908110[89] = 0.0;
   out_5030482369160908110[90] = 0.0;
   out_5030482369160908110[91] = 0.0;
   out_5030482369160908110[92] = 0.0;
   out_5030482369160908110[93] = 0.0;
   out_5030482369160908110[94] = 0.0;
   out_5030482369160908110[95] = 1.0;
   out_5030482369160908110[96] = 0.0;
   out_5030482369160908110[97] = 0.0;
   out_5030482369160908110[98] = 0.0;
   out_5030482369160908110[99] = 0.0;
   out_5030482369160908110[100] = 0.0;
   out_5030482369160908110[101] = 0.0;
   out_5030482369160908110[102] = 0.0;
   out_5030482369160908110[103] = 0.0;
   out_5030482369160908110[104] = 0.0;
   out_5030482369160908110[105] = 0.0;
   out_5030482369160908110[106] = 0.0;
   out_5030482369160908110[107] = 0.0;
   out_5030482369160908110[108] = 0.0;
   out_5030482369160908110[109] = 0.0;
   out_5030482369160908110[110] = 0.0;
   out_5030482369160908110[111] = 0.0;
   out_5030482369160908110[112] = 0.0;
   out_5030482369160908110[113] = 0.0;
   out_5030482369160908110[114] = 1.0;
   out_5030482369160908110[115] = 0.0;
   out_5030482369160908110[116] = 0.0;
   out_5030482369160908110[117] = 0.0;
   out_5030482369160908110[118] = 0.0;
   out_5030482369160908110[119] = 0.0;
   out_5030482369160908110[120] = 0.0;
   out_5030482369160908110[121] = 0.0;
   out_5030482369160908110[122] = 0.0;
   out_5030482369160908110[123] = 0.0;
   out_5030482369160908110[124] = 0.0;
   out_5030482369160908110[125] = 0.0;
   out_5030482369160908110[126] = 0.0;
   out_5030482369160908110[127] = 0.0;
   out_5030482369160908110[128] = 0.0;
   out_5030482369160908110[129] = 0.0;
   out_5030482369160908110[130] = 0.0;
   out_5030482369160908110[131] = 0.0;
   out_5030482369160908110[132] = 0.0;
   out_5030482369160908110[133] = 1.0;
   out_5030482369160908110[134] = 0.0;
   out_5030482369160908110[135] = 0.0;
   out_5030482369160908110[136] = 0.0;
   out_5030482369160908110[137] = 0.0;
   out_5030482369160908110[138] = 0.0;
   out_5030482369160908110[139] = 0.0;
   out_5030482369160908110[140] = 0.0;
   out_5030482369160908110[141] = 0.0;
   out_5030482369160908110[142] = 0.0;
   out_5030482369160908110[143] = 0.0;
   out_5030482369160908110[144] = 0.0;
   out_5030482369160908110[145] = 0.0;
   out_5030482369160908110[146] = 0.0;
   out_5030482369160908110[147] = 0.0;
   out_5030482369160908110[148] = 0.0;
   out_5030482369160908110[149] = 0.0;
   out_5030482369160908110[150] = 0.0;
   out_5030482369160908110[151] = 0.0;
   out_5030482369160908110[152] = 1.0;
   out_5030482369160908110[153] = 0.0;
   out_5030482369160908110[154] = 0.0;
   out_5030482369160908110[155] = 0.0;
   out_5030482369160908110[156] = 0.0;
   out_5030482369160908110[157] = 0.0;
   out_5030482369160908110[158] = 0.0;
   out_5030482369160908110[159] = 0.0;
   out_5030482369160908110[160] = 0.0;
   out_5030482369160908110[161] = 0.0;
   out_5030482369160908110[162] = 0.0;
   out_5030482369160908110[163] = 0.0;
   out_5030482369160908110[164] = 0.0;
   out_5030482369160908110[165] = 0.0;
   out_5030482369160908110[166] = 0.0;
   out_5030482369160908110[167] = 0.0;
   out_5030482369160908110[168] = 0.0;
   out_5030482369160908110[169] = 0.0;
   out_5030482369160908110[170] = 0.0;
   out_5030482369160908110[171] = 1.0;
   out_5030482369160908110[172] = 0.0;
   out_5030482369160908110[173] = 0.0;
   out_5030482369160908110[174] = 0.0;
   out_5030482369160908110[175] = 0.0;
   out_5030482369160908110[176] = 0.0;
   out_5030482369160908110[177] = 0.0;
   out_5030482369160908110[178] = 0.0;
   out_5030482369160908110[179] = 0.0;
   out_5030482369160908110[180] = 0.0;
   out_5030482369160908110[181] = 0.0;
   out_5030482369160908110[182] = 0.0;
   out_5030482369160908110[183] = 0.0;
   out_5030482369160908110[184] = 0.0;
   out_5030482369160908110[185] = 0.0;
   out_5030482369160908110[186] = 0.0;
   out_5030482369160908110[187] = 0.0;
   out_5030482369160908110[188] = 0.0;
   out_5030482369160908110[189] = 0.0;
   out_5030482369160908110[190] = 1.0;
   out_5030482369160908110[191] = 0.0;
   out_5030482369160908110[192] = 0.0;
   out_5030482369160908110[193] = 0.0;
   out_5030482369160908110[194] = 0.0;
   out_5030482369160908110[195] = 0.0;
   out_5030482369160908110[196] = 0.0;
   out_5030482369160908110[197] = 0.0;
   out_5030482369160908110[198] = 0.0;
   out_5030482369160908110[199] = 0.0;
   out_5030482369160908110[200] = 0.0;
   out_5030482369160908110[201] = 0.0;
   out_5030482369160908110[202] = 0.0;
   out_5030482369160908110[203] = 0.0;
   out_5030482369160908110[204] = 0.0;
   out_5030482369160908110[205] = 0.0;
   out_5030482369160908110[206] = 0.0;
   out_5030482369160908110[207] = 0.0;
   out_5030482369160908110[208] = 0.0;
   out_5030482369160908110[209] = 1.0;
   out_5030482369160908110[210] = 0.0;
   out_5030482369160908110[211] = 0.0;
   out_5030482369160908110[212] = 0.0;
   out_5030482369160908110[213] = 0.0;
   out_5030482369160908110[214] = 0.0;
   out_5030482369160908110[215] = 0.0;
   out_5030482369160908110[216] = 0.0;
   out_5030482369160908110[217] = 0.0;
   out_5030482369160908110[218] = 0.0;
   out_5030482369160908110[219] = 0.0;
   out_5030482369160908110[220] = 0.0;
   out_5030482369160908110[221] = 0.0;
   out_5030482369160908110[222] = 0.0;
   out_5030482369160908110[223] = 0.0;
   out_5030482369160908110[224] = 0.0;
   out_5030482369160908110[225] = 0.0;
   out_5030482369160908110[226] = 0.0;
   out_5030482369160908110[227] = 0.0;
   out_5030482369160908110[228] = 1.0;
   out_5030482369160908110[229] = 0.0;
   out_5030482369160908110[230] = 0.0;
   out_5030482369160908110[231] = 0.0;
   out_5030482369160908110[232] = 0.0;
   out_5030482369160908110[233] = 0.0;
   out_5030482369160908110[234] = 0.0;
   out_5030482369160908110[235] = 0.0;
   out_5030482369160908110[236] = 0.0;
   out_5030482369160908110[237] = 0.0;
   out_5030482369160908110[238] = 0.0;
   out_5030482369160908110[239] = 0.0;
   out_5030482369160908110[240] = 0.0;
   out_5030482369160908110[241] = 0.0;
   out_5030482369160908110[242] = 0.0;
   out_5030482369160908110[243] = 0.0;
   out_5030482369160908110[244] = 0.0;
   out_5030482369160908110[245] = 0.0;
   out_5030482369160908110[246] = 0.0;
   out_5030482369160908110[247] = 1.0;
   out_5030482369160908110[248] = 0.0;
   out_5030482369160908110[249] = 0.0;
   out_5030482369160908110[250] = 0.0;
   out_5030482369160908110[251] = 0.0;
   out_5030482369160908110[252] = 0.0;
   out_5030482369160908110[253] = 0.0;
   out_5030482369160908110[254] = 0.0;
   out_5030482369160908110[255] = 0.0;
   out_5030482369160908110[256] = 0.0;
   out_5030482369160908110[257] = 0.0;
   out_5030482369160908110[258] = 0.0;
   out_5030482369160908110[259] = 0.0;
   out_5030482369160908110[260] = 0.0;
   out_5030482369160908110[261] = 0.0;
   out_5030482369160908110[262] = 0.0;
   out_5030482369160908110[263] = 0.0;
   out_5030482369160908110[264] = 0.0;
   out_5030482369160908110[265] = 0.0;
   out_5030482369160908110[266] = 1.0;
   out_5030482369160908110[267] = 0.0;
   out_5030482369160908110[268] = 0.0;
   out_5030482369160908110[269] = 0.0;
   out_5030482369160908110[270] = 0.0;
   out_5030482369160908110[271] = 0.0;
   out_5030482369160908110[272] = 0.0;
   out_5030482369160908110[273] = 0.0;
   out_5030482369160908110[274] = 0.0;
   out_5030482369160908110[275] = 0.0;
   out_5030482369160908110[276] = 0.0;
   out_5030482369160908110[277] = 0.0;
   out_5030482369160908110[278] = 0.0;
   out_5030482369160908110[279] = 0.0;
   out_5030482369160908110[280] = 0.0;
   out_5030482369160908110[281] = 0.0;
   out_5030482369160908110[282] = 0.0;
   out_5030482369160908110[283] = 0.0;
   out_5030482369160908110[284] = 0.0;
   out_5030482369160908110[285] = 1.0;
   out_5030482369160908110[286] = 0.0;
   out_5030482369160908110[287] = 0.0;
   out_5030482369160908110[288] = 0.0;
   out_5030482369160908110[289] = 0.0;
   out_5030482369160908110[290] = 0.0;
   out_5030482369160908110[291] = 0.0;
   out_5030482369160908110[292] = 0.0;
   out_5030482369160908110[293] = 0.0;
   out_5030482369160908110[294] = 0.0;
   out_5030482369160908110[295] = 0.0;
   out_5030482369160908110[296] = 0.0;
   out_5030482369160908110[297] = 0.0;
   out_5030482369160908110[298] = 0.0;
   out_5030482369160908110[299] = 0.0;
   out_5030482369160908110[300] = 0.0;
   out_5030482369160908110[301] = 0.0;
   out_5030482369160908110[302] = 0.0;
   out_5030482369160908110[303] = 0.0;
   out_5030482369160908110[304] = 1.0;
   out_5030482369160908110[305] = 0.0;
   out_5030482369160908110[306] = 0.0;
   out_5030482369160908110[307] = 0.0;
   out_5030482369160908110[308] = 0.0;
   out_5030482369160908110[309] = 0.0;
   out_5030482369160908110[310] = 0.0;
   out_5030482369160908110[311] = 0.0;
   out_5030482369160908110[312] = 0.0;
   out_5030482369160908110[313] = 0.0;
   out_5030482369160908110[314] = 0.0;
   out_5030482369160908110[315] = 0.0;
   out_5030482369160908110[316] = 0.0;
   out_5030482369160908110[317] = 0.0;
   out_5030482369160908110[318] = 0.0;
   out_5030482369160908110[319] = 0.0;
   out_5030482369160908110[320] = 0.0;
   out_5030482369160908110[321] = 0.0;
   out_5030482369160908110[322] = 0.0;
   out_5030482369160908110[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1235990561508542419) {
   out_1235990561508542419[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1235990561508542419[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1235990561508542419[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1235990561508542419[3] = dt*state[12] + state[3];
   out_1235990561508542419[4] = dt*state[13] + state[4];
   out_1235990561508542419[5] = dt*state[14] + state[5];
   out_1235990561508542419[6] = state[6];
   out_1235990561508542419[7] = state[7];
   out_1235990561508542419[8] = state[8];
   out_1235990561508542419[9] = state[9];
   out_1235990561508542419[10] = state[10];
   out_1235990561508542419[11] = state[11];
   out_1235990561508542419[12] = state[12];
   out_1235990561508542419[13] = state[13];
   out_1235990561508542419[14] = state[14];
   out_1235990561508542419[15] = state[15];
   out_1235990561508542419[16] = state[16];
   out_1235990561508542419[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1393525693373603519) {
   out_1393525693373603519[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1393525693373603519[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1393525693373603519[2] = 0;
   out_1393525693373603519[3] = 0;
   out_1393525693373603519[4] = 0;
   out_1393525693373603519[5] = 0;
   out_1393525693373603519[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1393525693373603519[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1393525693373603519[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1393525693373603519[9] = 0;
   out_1393525693373603519[10] = 0;
   out_1393525693373603519[11] = 0;
   out_1393525693373603519[12] = 0;
   out_1393525693373603519[13] = 0;
   out_1393525693373603519[14] = 0;
   out_1393525693373603519[15] = 0;
   out_1393525693373603519[16] = 0;
   out_1393525693373603519[17] = 0;
   out_1393525693373603519[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1393525693373603519[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1393525693373603519[20] = 0;
   out_1393525693373603519[21] = 0;
   out_1393525693373603519[22] = 0;
   out_1393525693373603519[23] = 0;
   out_1393525693373603519[24] = 0;
   out_1393525693373603519[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1393525693373603519[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1393525693373603519[27] = 0;
   out_1393525693373603519[28] = 0;
   out_1393525693373603519[29] = 0;
   out_1393525693373603519[30] = 0;
   out_1393525693373603519[31] = 0;
   out_1393525693373603519[32] = 0;
   out_1393525693373603519[33] = 0;
   out_1393525693373603519[34] = 0;
   out_1393525693373603519[35] = 0;
   out_1393525693373603519[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1393525693373603519[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1393525693373603519[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1393525693373603519[39] = 0;
   out_1393525693373603519[40] = 0;
   out_1393525693373603519[41] = 0;
   out_1393525693373603519[42] = 0;
   out_1393525693373603519[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1393525693373603519[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1393525693373603519[45] = 0;
   out_1393525693373603519[46] = 0;
   out_1393525693373603519[47] = 0;
   out_1393525693373603519[48] = 0;
   out_1393525693373603519[49] = 0;
   out_1393525693373603519[50] = 0;
   out_1393525693373603519[51] = 0;
   out_1393525693373603519[52] = 0;
   out_1393525693373603519[53] = 0;
   out_1393525693373603519[54] = 0;
   out_1393525693373603519[55] = 0;
   out_1393525693373603519[56] = 0;
   out_1393525693373603519[57] = 1;
   out_1393525693373603519[58] = 0;
   out_1393525693373603519[59] = 0;
   out_1393525693373603519[60] = 0;
   out_1393525693373603519[61] = 0;
   out_1393525693373603519[62] = 0;
   out_1393525693373603519[63] = 0;
   out_1393525693373603519[64] = 0;
   out_1393525693373603519[65] = 0;
   out_1393525693373603519[66] = dt;
   out_1393525693373603519[67] = 0;
   out_1393525693373603519[68] = 0;
   out_1393525693373603519[69] = 0;
   out_1393525693373603519[70] = 0;
   out_1393525693373603519[71] = 0;
   out_1393525693373603519[72] = 0;
   out_1393525693373603519[73] = 0;
   out_1393525693373603519[74] = 0;
   out_1393525693373603519[75] = 0;
   out_1393525693373603519[76] = 1;
   out_1393525693373603519[77] = 0;
   out_1393525693373603519[78] = 0;
   out_1393525693373603519[79] = 0;
   out_1393525693373603519[80] = 0;
   out_1393525693373603519[81] = 0;
   out_1393525693373603519[82] = 0;
   out_1393525693373603519[83] = 0;
   out_1393525693373603519[84] = 0;
   out_1393525693373603519[85] = dt;
   out_1393525693373603519[86] = 0;
   out_1393525693373603519[87] = 0;
   out_1393525693373603519[88] = 0;
   out_1393525693373603519[89] = 0;
   out_1393525693373603519[90] = 0;
   out_1393525693373603519[91] = 0;
   out_1393525693373603519[92] = 0;
   out_1393525693373603519[93] = 0;
   out_1393525693373603519[94] = 0;
   out_1393525693373603519[95] = 1;
   out_1393525693373603519[96] = 0;
   out_1393525693373603519[97] = 0;
   out_1393525693373603519[98] = 0;
   out_1393525693373603519[99] = 0;
   out_1393525693373603519[100] = 0;
   out_1393525693373603519[101] = 0;
   out_1393525693373603519[102] = 0;
   out_1393525693373603519[103] = 0;
   out_1393525693373603519[104] = dt;
   out_1393525693373603519[105] = 0;
   out_1393525693373603519[106] = 0;
   out_1393525693373603519[107] = 0;
   out_1393525693373603519[108] = 0;
   out_1393525693373603519[109] = 0;
   out_1393525693373603519[110] = 0;
   out_1393525693373603519[111] = 0;
   out_1393525693373603519[112] = 0;
   out_1393525693373603519[113] = 0;
   out_1393525693373603519[114] = 1;
   out_1393525693373603519[115] = 0;
   out_1393525693373603519[116] = 0;
   out_1393525693373603519[117] = 0;
   out_1393525693373603519[118] = 0;
   out_1393525693373603519[119] = 0;
   out_1393525693373603519[120] = 0;
   out_1393525693373603519[121] = 0;
   out_1393525693373603519[122] = 0;
   out_1393525693373603519[123] = 0;
   out_1393525693373603519[124] = 0;
   out_1393525693373603519[125] = 0;
   out_1393525693373603519[126] = 0;
   out_1393525693373603519[127] = 0;
   out_1393525693373603519[128] = 0;
   out_1393525693373603519[129] = 0;
   out_1393525693373603519[130] = 0;
   out_1393525693373603519[131] = 0;
   out_1393525693373603519[132] = 0;
   out_1393525693373603519[133] = 1;
   out_1393525693373603519[134] = 0;
   out_1393525693373603519[135] = 0;
   out_1393525693373603519[136] = 0;
   out_1393525693373603519[137] = 0;
   out_1393525693373603519[138] = 0;
   out_1393525693373603519[139] = 0;
   out_1393525693373603519[140] = 0;
   out_1393525693373603519[141] = 0;
   out_1393525693373603519[142] = 0;
   out_1393525693373603519[143] = 0;
   out_1393525693373603519[144] = 0;
   out_1393525693373603519[145] = 0;
   out_1393525693373603519[146] = 0;
   out_1393525693373603519[147] = 0;
   out_1393525693373603519[148] = 0;
   out_1393525693373603519[149] = 0;
   out_1393525693373603519[150] = 0;
   out_1393525693373603519[151] = 0;
   out_1393525693373603519[152] = 1;
   out_1393525693373603519[153] = 0;
   out_1393525693373603519[154] = 0;
   out_1393525693373603519[155] = 0;
   out_1393525693373603519[156] = 0;
   out_1393525693373603519[157] = 0;
   out_1393525693373603519[158] = 0;
   out_1393525693373603519[159] = 0;
   out_1393525693373603519[160] = 0;
   out_1393525693373603519[161] = 0;
   out_1393525693373603519[162] = 0;
   out_1393525693373603519[163] = 0;
   out_1393525693373603519[164] = 0;
   out_1393525693373603519[165] = 0;
   out_1393525693373603519[166] = 0;
   out_1393525693373603519[167] = 0;
   out_1393525693373603519[168] = 0;
   out_1393525693373603519[169] = 0;
   out_1393525693373603519[170] = 0;
   out_1393525693373603519[171] = 1;
   out_1393525693373603519[172] = 0;
   out_1393525693373603519[173] = 0;
   out_1393525693373603519[174] = 0;
   out_1393525693373603519[175] = 0;
   out_1393525693373603519[176] = 0;
   out_1393525693373603519[177] = 0;
   out_1393525693373603519[178] = 0;
   out_1393525693373603519[179] = 0;
   out_1393525693373603519[180] = 0;
   out_1393525693373603519[181] = 0;
   out_1393525693373603519[182] = 0;
   out_1393525693373603519[183] = 0;
   out_1393525693373603519[184] = 0;
   out_1393525693373603519[185] = 0;
   out_1393525693373603519[186] = 0;
   out_1393525693373603519[187] = 0;
   out_1393525693373603519[188] = 0;
   out_1393525693373603519[189] = 0;
   out_1393525693373603519[190] = 1;
   out_1393525693373603519[191] = 0;
   out_1393525693373603519[192] = 0;
   out_1393525693373603519[193] = 0;
   out_1393525693373603519[194] = 0;
   out_1393525693373603519[195] = 0;
   out_1393525693373603519[196] = 0;
   out_1393525693373603519[197] = 0;
   out_1393525693373603519[198] = 0;
   out_1393525693373603519[199] = 0;
   out_1393525693373603519[200] = 0;
   out_1393525693373603519[201] = 0;
   out_1393525693373603519[202] = 0;
   out_1393525693373603519[203] = 0;
   out_1393525693373603519[204] = 0;
   out_1393525693373603519[205] = 0;
   out_1393525693373603519[206] = 0;
   out_1393525693373603519[207] = 0;
   out_1393525693373603519[208] = 0;
   out_1393525693373603519[209] = 1;
   out_1393525693373603519[210] = 0;
   out_1393525693373603519[211] = 0;
   out_1393525693373603519[212] = 0;
   out_1393525693373603519[213] = 0;
   out_1393525693373603519[214] = 0;
   out_1393525693373603519[215] = 0;
   out_1393525693373603519[216] = 0;
   out_1393525693373603519[217] = 0;
   out_1393525693373603519[218] = 0;
   out_1393525693373603519[219] = 0;
   out_1393525693373603519[220] = 0;
   out_1393525693373603519[221] = 0;
   out_1393525693373603519[222] = 0;
   out_1393525693373603519[223] = 0;
   out_1393525693373603519[224] = 0;
   out_1393525693373603519[225] = 0;
   out_1393525693373603519[226] = 0;
   out_1393525693373603519[227] = 0;
   out_1393525693373603519[228] = 1;
   out_1393525693373603519[229] = 0;
   out_1393525693373603519[230] = 0;
   out_1393525693373603519[231] = 0;
   out_1393525693373603519[232] = 0;
   out_1393525693373603519[233] = 0;
   out_1393525693373603519[234] = 0;
   out_1393525693373603519[235] = 0;
   out_1393525693373603519[236] = 0;
   out_1393525693373603519[237] = 0;
   out_1393525693373603519[238] = 0;
   out_1393525693373603519[239] = 0;
   out_1393525693373603519[240] = 0;
   out_1393525693373603519[241] = 0;
   out_1393525693373603519[242] = 0;
   out_1393525693373603519[243] = 0;
   out_1393525693373603519[244] = 0;
   out_1393525693373603519[245] = 0;
   out_1393525693373603519[246] = 0;
   out_1393525693373603519[247] = 1;
   out_1393525693373603519[248] = 0;
   out_1393525693373603519[249] = 0;
   out_1393525693373603519[250] = 0;
   out_1393525693373603519[251] = 0;
   out_1393525693373603519[252] = 0;
   out_1393525693373603519[253] = 0;
   out_1393525693373603519[254] = 0;
   out_1393525693373603519[255] = 0;
   out_1393525693373603519[256] = 0;
   out_1393525693373603519[257] = 0;
   out_1393525693373603519[258] = 0;
   out_1393525693373603519[259] = 0;
   out_1393525693373603519[260] = 0;
   out_1393525693373603519[261] = 0;
   out_1393525693373603519[262] = 0;
   out_1393525693373603519[263] = 0;
   out_1393525693373603519[264] = 0;
   out_1393525693373603519[265] = 0;
   out_1393525693373603519[266] = 1;
   out_1393525693373603519[267] = 0;
   out_1393525693373603519[268] = 0;
   out_1393525693373603519[269] = 0;
   out_1393525693373603519[270] = 0;
   out_1393525693373603519[271] = 0;
   out_1393525693373603519[272] = 0;
   out_1393525693373603519[273] = 0;
   out_1393525693373603519[274] = 0;
   out_1393525693373603519[275] = 0;
   out_1393525693373603519[276] = 0;
   out_1393525693373603519[277] = 0;
   out_1393525693373603519[278] = 0;
   out_1393525693373603519[279] = 0;
   out_1393525693373603519[280] = 0;
   out_1393525693373603519[281] = 0;
   out_1393525693373603519[282] = 0;
   out_1393525693373603519[283] = 0;
   out_1393525693373603519[284] = 0;
   out_1393525693373603519[285] = 1;
   out_1393525693373603519[286] = 0;
   out_1393525693373603519[287] = 0;
   out_1393525693373603519[288] = 0;
   out_1393525693373603519[289] = 0;
   out_1393525693373603519[290] = 0;
   out_1393525693373603519[291] = 0;
   out_1393525693373603519[292] = 0;
   out_1393525693373603519[293] = 0;
   out_1393525693373603519[294] = 0;
   out_1393525693373603519[295] = 0;
   out_1393525693373603519[296] = 0;
   out_1393525693373603519[297] = 0;
   out_1393525693373603519[298] = 0;
   out_1393525693373603519[299] = 0;
   out_1393525693373603519[300] = 0;
   out_1393525693373603519[301] = 0;
   out_1393525693373603519[302] = 0;
   out_1393525693373603519[303] = 0;
   out_1393525693373603519[304] = 1;
   out_1393525693373603519[305] = 0;
   out_1393525693373603519[306] = 0;
   out_1393525693373603519[307] = 0;
   out_1393525693373603519[308] = 0;
   out_1393525693373603519[309] = 0;
   out_1393525693373603519[310] = 0;
   out_1393525693373603519[311] = 0;
   out_1393525693373603519[312] = 0;
   out_1393525693373603519[313] = 0;
   out_1393525693373603519[314] = 0;
   out_1393525693373603519[315] = 0;
   out_1393525693373603519[316] = 0;
   out_1393525693373603519[317] = 0;
   out_1393525693373603519[318] = 0;
   out_1393525693373603519[319] = 0;
   out_1393525693373603519[320] = 0;
   out_1393525693373603519[321] = 0;
   out_1393525693373603519[322] = 0;
   out_1393525693373603519[323] = 1;
}
void h_4(double *state, double *unused, double *out_1733375464843140313) {
   out_1733375464843140313[0] = state[6] + state[9];
   out_1733375464843140313[1] = state[7] + state[10];
   out_1733375464843140313[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6850181095067204971) {
   out_6850181095067204971[0] = 0;
   out_6850181095067204971[1] = 0;
   out_6850181095067204971[2] = 0;
   out_6850181095067204971[3] = 0;
   out_6850181095067204971[4] = 0;
   out_6850181095067204971[5] = 0;
   out_6850181095067204971[6] = 1;
   out_6850181095067204971[7] = 0;
   out_6850181095067204971[8] = 0;
   out_6850181095067204971[9] = 1;
   out_6850181095067204971[10] = 0;
   out_6850181095067204971[11] = 0;
   out_6850181095067204971[12] = 0;
   out_6850181095067204971[13] = 0;
   out_6850181095067204971[14] = 0;
   out_6850181095067204971[15] = 0;
   out_6850181095067204971[16] = 0;
   out_6850181095067204971[17] = 0;
   out_6850181095067204971[18] = 0;
   out_6850181095067204971[19] = 0;
   out_6850181095067204971[20] = 0;
   out_6850181095067204971[21] = 0;
   out_6850181095067204971[22] = 0;
   out_6850181095067204971[23] = 0;
   out_6850181095067204971[24] = 0;
   out_6850181095067204971[25] = 1;
   out_6850181095067204971[26] = 0;
   out_6850181095067204971[27] = 0;
   out_6850181095067204971[28] = 1;
   out_6850181095067204971[29] = 0;
   out_6850181095067204971[30] = 0;
   out_6850181095067204971[31] = 0;
   out_6850181095067204971[32] = 0;
   out_6850181095067204971[33] = 0;
   out_6850181095067204971[34] = 0;
   out_6850181095067204971[35] = 0;
   out_6850181095067204971[36] = 0;
   out_6850181095067204971[37] = 0;
   out_6850181095067204971[38] = 0;
   out_6850181095067204971[39] = 0;
   out_6850181095067204971[40] = 0;
   out_6850181095067204971[41] = 0;
   out_6850181095067204971[42] = 0;
   out_6850181095067204971[43] = 0;
   out_6850181095067204971[44] = 1;
   out_6850181095067204971[45] = 0;
   out_6850181095067204971[46] = 0;
   out_6850181095067204971[47] = 1;
   out_6850181095067204971[48] = 0;
   out_6850181095067204971[49] = 0;
   out_6850181095067204971[50] = 0;
   out_6850181095067204971[51] = 0;
   out_6850181095067204971[52] = 0;
   out_6850181095067204971[53] = 0;
}
void h_10(double *state, double *unused, double *out_1803459148168206843) {
   out_1803459148168206843[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1803459148168206843[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1803459148168206843[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1870184976953523917) {
   out_1870184976953523917[0] = 0;
   out_1870184976953523917[1] = 9.8100000000000005*cos(state[1]);
   out_1870184976953523917[2] = 0;
   out_1870184976953523917[3] = 0;
   out_1870184976953523917[4] = -state[8];
   out_1870184976953523917[5] = state[7];
   out_1870184976953523917[6] = 0;
   out_1870184976953523917[7] = state[5];
   out_1870184976953523917[8] = -state[4];
   out_1870184976953523917[9] = 0;
   out_1870184976953523917[10] = 0;
   out_1870184976953523917[11] = 0;
   out_1870184976953523917[12] = 1;
   out_1870184976953523917[13] = 0;
   out_1870184976953523917[14] = 0;
   out_1870184976953523917[15] = 1;
   out_1870184976953523917[16] = 0;
   out_1870184976953523917[17] = 0;
   out_1870184976953523917[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1870184976953523917[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1870184976953523917[20] = 0;
   out_1870184976953523917[21] = state[8];
   out_1870184976953523917[22] = 0;
   out_1870184976953523917[23] = -state[6];
   out_1870184976953523917[24] = -state[5];
   out_1870184976953523917[25] = 0;
   out_1870184976953523917[26] = state[3];
   out_1870184976953523917[27] = 0;
   out_1870184976953523917[28] = 0;
   out_1870184976953523917[29] = 0;
   out_1870184976953523917[30] = 0;
   out_1870184976953523917[31] = 1;
   out_1870184976953523917[32] = 0;
   out_1870184976953523917[33] = 0;
   out_1870184976953523917[34] = 1;
   out_1870184976953523917[35] = 0;
   out_1870184976953523917[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1870184976953523917[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1870184976953523917[38] = 0;
   out_1870184976953523917[39] = -state[7];
   out_1870184976953523917[40] = state[6];
   out_1870184976953523917[41] = 0;
   out_1870184976953523917[42] = state[4];
   out_1870184976953523917[43] = -state[3];
   out_1870184976953523917[44] = 0;
   out_1870184976953523917[45] = 0;
   out_1870184976953523917[46] = 0;
   out_1870184976953523917[47] = 0;
   out_1870184976953523917[48] = 0;
   out_1870184976953523917[49] = 0;
   out_1870184976953523917[50] = 1;
   out_1870184976953523917[51] = 0;
   out_1870184976953523917[52] = 0;
   out_1870184976953523917[53] = 1;
}
void h_13(double *state, double *unused, double *out_5196198746117623945) {
   out_5196198746117623945[0] = state[3];
   out_5196198746117623945[1] = state[4];
   out_5196198746117623945[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3637907269734872170) {
   out_3637907269734872170[0] = 0;
   out_3637907269734872170[1] = 0;
   out_3637907269734872170[2] = 0;
   out_3637907269734872170[3] = 1;
   out_3637907269734872170[4] = 0;
   out_3637907269734872170[5] = 0;
   out_3637907269734872170[6] = 0;
   out_3637907269734872170[7] = 0;
   out_3637907269734872170[8] = 0;
   out_3637907269734872170[9] = 0;
   out_3637907269734872170[10] = 0;
   out_3637907269734872170[11] = 0;
   out_3637907269734872170[12] = 0;
   out_3637907269734872170[13] = 0;
   out_3637907269734872170[14] = 0;
   out_3637907269734872170[15] = 0;
   out_3637907269734872170[16] = 0;
   out_3637907269734872170[17] = 0;
   out_3637907269734872170[18] = 0;
   out_3637907269734872170[19] = 0;
   out_3637907269734872170[20] = 0;
   out_3637907269734872170[21] = 0;
   out_3637907269734872170[22] = 1;
   out_3637907269734872170[23] = 0;
   out_3637907269734872170[24] = 0;
   out_3637907269734872170[25] = 0;
   out_3637907269734872170[26] = 0;
   out_3637907269734872170[27] = 0;
   out_3637907269734872170[28] = 0;
   out_3637907269734872170[29] = 0;
   out_3637907269734872170[30] = 0;
   out_3637907269734872170[31] = 0;
   out_3637907269734872170[32] = 0;
   out_3637907269734872170[33] = 0;
   out_3637907269734872170[34] = 0;
   out_3637907269734872170[35] = 0;
   out_3637907269734872170[36] = 0;
   out_3637907269734872170[37] = 0;
   out_3637907269734872170[38] = 0;
   out_3637907269734872170[39] = 0;
   out_3637907269734872170[40] = 0;
   out_3637907269734872170[41] = 1;
   out_3637907269734872170[42] = 0;
   out_3637907269734872170[43] = 0;
   out_3637907269734872170[44] = 0;
   out_3637907269734872170[45] = 0;
   out_3637907269734872170[46] = 0;
   out_3637907269734872170[47] = 0;
   out_3637907269734872170[48] = 0;
   out_3637907269734872170[49] = 0;
   out_3637907269734872170[50] = 0;
   out_3637907269734872170[51] = 0;
   out_3637907269734872170[52] = 0;
   out_3637907269734872170[53] = 0;
}
void h_14(double *state, double *unused, double *out_2301659273555299219) {
   out_2301659273555299219[0] = state[6];
   out_2301659273555299219[1] = state[7];
   out_2301659273555299219[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2886940238727720442) {
   out_2886940238727720442[0] = 0;
   out_2886940238727720442[1] = 0;
   out_2886940238727720442[2] = 0;
   out_2886940238727720442[3] = 0;
   out_2886940238727720442[4] = 0;
   out_2886940238727720442[5] = 0;
   out_2886940238727720442[6] = 1;
   out_2886940238727720442[7] = 0;
   out_2886940238727720442[8] = 0;
   out_2886940238727720442[9] = 0;
   out_2886940238727720442[10] = 0;
   out_2886940238727720442[11] = 0;
   out_2886940238727720442[12] = 0;
   out_2886940238727720442[13] = 0;
   out_2886940238727720442[14] = 0;
   out_2886940238727720442[15] = 0;
   out_2886940238727720442[16] = 0;
   out_2886940238727720442[17] = 0;
   out_2886940238727720442[18] = 0;
   out_2886940238727720442[19] = 0;
   out_2886940238727720442[20] = 0;
   out_2886940238727720442[21] = 0;
   out_2886940238727720442[22] = 0;
   out_2886940238727720442[23] = 0;
   out_2886940238727720442[24] = 0;
   out_2886940238727720442[25] = 1;
   out_2886940238727720442[26] = 0;
   out_2886940238727720442[27] = 0;
   out_2886940238727720442[28] = 0;
   out_2886940238727720442[29] = 0;
   out_2886940238727720442[30] = 0;
   out_2886940238727720442[31] = 0;
   out_2886940238727720442[32] = 0;
   out_2886940238727720442[33] = 0;
   out_2886940238727720442[34] = 0;
   out_2886940238727720442[35] = 0;
   out_2886940238727720442[36] = 0;
   out_2886940238727720442[37] = 0;
   out_2886940238727720442[38] = 0;
   out_2886940238727720442[39] = 0;
   out_2886940238727720442[40] = 0;
   out_2886940238727720442[41] = 0;
   out_2886940238727720442[42] = 0;
   out_2886940238727720442[43] = 0;
   out_2886940238727720442[44] = 1;
   out_2886940238727720442[45] = 0;
   out_2886940238727720442[46] = 0;
   out_2886940238727720442[47] = 0;
   out_2886940238727720442[48] = 0;
   out_2886940238727720442[49] = 0;
   out_2886940238727720442[50] = 0;
   out_2886940238727720442[51] = 0;
   out_2886940238727720442[52] = 0;
   out_2886940238727720442[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_2603305221510379343) {
  err_fun(nom_x, delta_x, out_2603305221510379343);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4906336809504339286) {
  inv_err_fun(nom_x, true_x, out_4906336809504339286);
}
void pose_H_mod_fun(double *state, double *out_5030482369160908110) {
  H_mod_fun(state, out_5030482369160908110);
}
void pose_f_fun(double *state, double dt, double *out_1235990561508542419) {
  f_fun(state,  dt, out_1235990561508542419);
}
void pose_F_fun(double *state, double dt, double *out_1393525693373603519) {
  F_fun(state,  dt, out_1393525693373603519);
}
void pose_h_4(double *state, double *unused, double *out_1733375464843140313) {
  h_4(state, unused, out_1733375464843140313);
}
void pose_H_4(double *state, double *unused, double *out_6850181095067204971) {
  H_4(state, unused, out_6850181095067204971);
}
void pose_h_10(double *state, double *unused, double *out_1803459148168206843) {
  h_10(state, unused, out_1803459148168206843);
}
void pose_H_10(double *state, double *unused, double *out_1870184976953523917) {
  H_10(state, unused, out_1870184976953523917);
}
void pose_h_13(double *state, double *unused, double *out_5196198746117623945) {
  h_13(state, unused, out_5196198746117623945);
}
void pose_H_13(double *state, double *unused, double *out_3637907269734872170) {
  H_13(state, unused, out_3637907269734872170);
}
void pose_h_14(double *state, double *unused, double *out_2301659273555299219) {
  h_14(state, unused, out_2301659273555299219);
}
void pose_H_14(double *state, double *unused, double *out_2886940238727720442) {
  H_14(state, unused, out_2886940238727720442);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
