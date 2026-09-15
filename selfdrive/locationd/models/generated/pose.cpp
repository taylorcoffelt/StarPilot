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
void err_fun(double *nom_x, double *delta_x, double *out_6229004230267029840) {
   out_6229004230267029840[0] = delta_x[0] + nom_x[0];
   out_6229004230267029840[1] = delta_x[1] + nom_x[1];
   out_6229004230267029840[2] = delta_x[2] + nom_x[2];
   out_6229004230267029840[3] = delta_x[3] + nom_x[3];
   out_6229004230267029840[4] = delta_x[4] + nom_x[4];
   out_6229004230267029840[5] = delta_x[5] + nom_x[5];
   out_6229004230267029840[6] = delta_x[6] + nom_x[6];
   out_6229004230267029840[7] = delta_x[7] + nom_x[7];
   out_6229004230267029840[8] = delta_x[8] + nom_x[8];
   out_6229004230267029840[9] = delta_x[9] + nom_x[9];
   out_6229004230267029840[10] = delta_x[10] + nom_x[10];
   out_6229004230267029840[11] = delta_x[11] + nom_x[11];
   out_6229004230267029840[12] = delta_x[12] + nom_x[12];
   out_6229004230267029840[13] = delta_x[13] + nom_x[13];
   out_6229004230267029840[14] = delta_x[14] + nom_x[14];
   out_6229004230267029840[15] = delta_x[15] + nom_x[15];
   out_6229004230267029840[16] = delta_x[16] + nom_x[16];
   out_6229004230267029840[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7305334829560631632) {
   out_7305334829560631632[0] = -nom_x[0] + true_x[0];
   out_7305334829560631632[1] = -nom_x[1] + true_x[1];
   out_7305334829560631632[2] = -nom_x[2] + true_x[2];
   out_7305334829560631632[3] = -nom_x[3] + true_x[3];
   out_7305334829560631632[4] = -nom_x[4] + true_x[4];
   out_7305334829560631632[5] = -nom_x[5] + true_x[5];
   out_7305334829560631632[6] = -nom_x[6] + true_x[6];
   out_7305334829560631632[7] = -nom_x[7] + true_x[7];
   out_7305334829560631632[8] = -nom_x[8] + true_x[8];
   out_7305334829560631632[9] = -nom_x[9] + true_x[9];
   out_7305334829560631632[10] = -nom_x[10] + true_x[10];
   out_7305334829560631632[11] = -nom_x[11] + true_x[11];
   out_7305334829560631632[12] = -nom_x[12] + true_x[12];
   out_7305334829560631632[13] = -nom_x[13] + true_x[13];
   out_7305334829560631632[14] = -nom_x[14] + true_x[14];
   out_7305334829560631632[15] = -nom_x[15] + true_x[15];
   out_7305334829560631632[16] = -nom_x[16] + true_x[16];
   out_7305334829560631632[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6174181234683270111) {
   out_6174181234683270111[0] = 1.0;
   out_6174181234683270111[1] = 0.0;
   out_6174181234683270111[2] = 0.0;
   out_6174181234683270111[3] = 0.0;
   out_6174181234683270111[4] = 0.0;
   out_6174181234683270111[5] = 0.0;
   out_6174181234683270111[6] = 0.0;
   out_6174181234683270111[7] = 0.0;
   out_6174181234683270111[8] = 0.0;
   out_6174181234683270111[9] = 0.0;
   out_6174181234683270111[10] = 0.0;
   out_6174181234683270111[11] = 0.0;
   out_6174181234683270111[12] = 0.0;
   out_6174181234683270111[13] = 0.0;
   out_6174181234683270111[14] = 0.0;
   out_6174181234683270111[15] = 0.0;
   out_6174181234683270111[16] = 0.0;
   out_6174181234683270111[17] = 0.0;
   out_6174181234683270111[18] = 0.0;
   out_6174181234683270111[19] = 1.0;
   out_6174181234683270111[20] = 0.0;
   out_6174181234683270111[21] = 0.0;
   out_6174181234683270111[22] = 0.0;
   out_6174181234683270111[23] = 0.0;
   out_6174181234683270111[24] = 0.0;
   out_6174181234683270111[25] = 0.0;
   out_6174181234683270111[26] = 0.0;
   out_6174181234683270111[27] = 0.0;
   out_6174181234683270111[28] = 0.0;
   out_6174181234683270111[29] = 0.0;
   out_6174181234683270111[30] = 0.0;
   out_6174181234683270111[31] = 0.0;
   out_6174181234683270111[32] = 0.0;
   out_6174181234683270111[33] = 0.0;
   out_6174181234683270111[34] = 0.0;
   out_6174181234683270111[35] = 0.0;
   out_6174181234683270111[36] = 0.0;
   out_6174181234683270111[37] = 0.0;
   out_6174181234683270111[38] = 1.0;
   out_6174181234683270111[39] = 0.0;
   out_6174181234683270111[40] = 0.0;
   out_6174181234683270111[41] = 0.0;
   out_6174181234683270111[42] = 0.0;
   out_6174181234683270111[43] = 0.0;
   out_6174181234683270111[44] = 0.0;
   out_6174181234683270111[45] = 0.0;
   out_6174181234683270111[46] = 0.0;
   out_6174181234683270111[47] = 0.0;
   out_6174181234683270111[48] = 0.0;
   out_6174181234683270111[49] = 0.0;
   out_6174181234683270111[50] = 0.0;
   out_6174181234683270111[51] = 0.0;
   out_6174181234683270111[52] = 0.0;
   out_6174181234683270111[53] = 0.0;
   out_6174181234683270111[54] = 0.0;
   out_6174181234683270111[55] = 0.0;
   out_6174181234683270111[56] = 0.0;
   out_6174181234683270111[57] = 1.0;
   out_6174181234683270111[58] = 0.0;
   out_6174181234683270111[59] = 0.0;
   out_6174181234683270111[60] = 0.0;
   out_6174181234683270111[61] = 0.0;
   out_6174181234683270111[62] = 0.0;
   out_6174181234683270111[63] = 0.0;
   out_6174181234683270111[64] = 0.0;
   out_6174181234683270111[65] = 0.0;
   out_6174181234683270111[66] = 0.0;
   out_6174181234683270111[67] = 0.0;
   out_6174181234683270111[68] = 0.0;
   out_6174181234683270111[69] = 0.0;
   out_6174181234683270111[70] = 0.0;
   out_6174181234683270111[71] = 0.0;
   out_6174181234683270111[72] = 0.0;
   out_6174181234683270111[73] = 0.0;
   out_6174181234683270111[74] = 0.0;
   out_6174181234683270111[75] = 0.0;
   out_6174181234683270111[76] = 1.0;
   out_6174181234683270111[77] = 0.0;
   out_6174181234683270111[78] = 0.0;
   out_6174181234683270111[79] = 0.0;
   out_6174181234683270111[80] = 0.0;
   out_6174181234683270111[81] = 0.0;
   out_6174181234683270111[82] = 0.0;
   out_6174181234683270111[83] = 0.0;
   out_6174181234683270111[84] = 0.0;
   out_6174181234683270111[85] = 0.0;
   out_6174181234683270111[86] = 0.0;
   out_6174181234683270111[87] = 0.0;
   out_6174181234683270111[88] = 0.0;
   out_6174181234683270111[89] = 0.0;
   out_6174181234683270111[90] = 0.0;
   out_6174181234683270111[91] = 0.0;
   out_6174181234683270111[92] = 0.0;
   out_6174181234683270111[93] = 0.0;
   out_6174181234683270111[94] = 0.0;
   out_6174181234683270111[95] = 1.0;
   out_6174181234683270111[96] = 0.0;
   out_6174181234683270111[97] = 0.0;
   out_6174181234683270111[98] = 0.0;
   out_6174181234683270111[99] = 0.0;
   out_6174181234683270111[100] = 0.0;
   out_6174181234683270111[101] = 0.0;
   out_6174181234683270111[102] = 0.0;
   out_6174181234683270111[103] = 0.0;
   out_6174181234683270111[104] = 0.0;
   out_6174181234683270111[105] = 0.0;
   out_6174181234683270111[106] = 0.0;
   out_6174181234683270111[107] = 0.0;
   out_6174181234683270111[108] = 0.0;
   out_6174181234683270111[109] = 0.0;
   out_6174181234683270111[110] = 0.0;
   out_6174181234683270111[111] = 0.0;
   out_6174181234683270111[112] = 0.0;
   out_6174181234683270111[113] = 0.0;
   out_6174181234683270111[114] = 1.0;
   out_6174181234683270111[115] = 0.0;
   out_6174181234683270111[116] = 0.0;
   out_6174181234683270111[117] = 0.0;
   out_6174181234683270111[118] = 0.0;
   out_6174181234683270111[119] = 0.0;
   out_6174181234683270111[120] = 0.0;
   out_6174181234683270111[121] = 0.0;
   out_6174181234683270111[122] = 0.0;
   out_6174181234683270111[123] = 0.0;
   out_6174181234683270111[124] = 0.0;
   out_6174181234683270111[125] = 0.0;
   out_6174181234683270111[126] = 0.0;
   out_6174181234683270111[127] = 0.0;
   out_6174181234683270111[128] = 0.0;
   out_6174181234683270111[129] = 0.0;
   out_6174181234683270111[130] = 0.0;
   out_6174181234683270111[131] = 0.0;
   out_6174181234683270111[132] = 0.0;
   out_6174181234683270111[133] = 1.0;
   out_6174181234683270111[134] = 0.0;
   out_6174181234683270111[135] = 0.0;
   out_6174181234683270111[136] = 0.0;
   out_6174181234683270111[137] = 0.0;
   out_6174181234683270111[138] = 0.0;
   out_6174181234683270111[139] = 0.0;
   out_6174181234683270111[140] = 0.0;
   out_6174181234683270111[141] = 0.0;
   out_6174181234683270111[142] = 0.0;
   out_6174181234683270111[143] = 0.0;
   out_6174181234683270111[144] = 0.0;
   out_6174181234683270111[145] = 0.0;
   out_6174181234683270111[146] = 0.0;
   out_6174181234683270111[147] = 0.0;
   out_6174181234683270111[148] = 0.0;
   out_6174181234683270111[149] = 0.0;
   out_6174181234683270111[150] = 0.0;
   out_6174181234683270111[151] = 0.0;
   out_6174181234683270111[152] = 1.0;
   out_6174181234683270111[153] = 0.0;
   out_6174181234683270111[154] = 0.0;
   out_6174181234683270111[155] = 0.0;
   out_6174181234683270111[156] = 0.0;
   out_6174181234683270111[157] = 0.0;
   out_6174181234683270111[158] = 0.0;
   out_6174181234683270111[159] = 0.0;
   out_6174181234683270111[160] = 0.0;
   out_6174181234683270111[161] = 0.0;
   out_6174181234683270111[162] = 0.0;
   out_6174181234683270111[163] = 0.0;
   out_6174181234683270111[164] = 0.0;
   out_6174181234683270111[165] = 0.0;
   out_6174181234683270111[166] = 0.0;
   out_6174181234683270111[167] = 0.0;
   out_6174181234683270111[168] = 0.0;
   out_6174181234683270111[169] = 0.0;
   out_6174181234683270111[170] = 0.0;
   out_6174181234683270111[171] = 1.0;
   out_6174181234683270111[172] = 0.0;
   out_6174181234683270111[173] = 0.0;
   out_6174181234683270111[174] = 0.0;
   out_6174181234683270111[175] = 0.0;
   out_6174181234683270111[176] = 0.0;
   out_6174181234683270111[177] = 0.0;
   out_6174181234683270111[178] = 0.0;
   out_6174181234683270111[179] = 0.0;
   out_6174181234683270111[180] = 0.0;
   out_6174181234683270111[181] = 0.0;
   out_6174181234683270111[182] = 0.0;
   out_6174181234683270111[183] = 0.0;
   out_6174181234683270111[184] = 0.0;
   out_6174181234683270111[185] = 0.0;
   out_6174181234683270111[186] = 0.0;
   out_6174181234683270111[187] = 0.0;
   out_6174181234683270111[188] = 0.0;
   out_6174181234683270111[189] = 0.0;
   out_6174181234683270111[190] = 1.0;
   out_6174181234683270111[191] = 0.0;
   out_6174181234683270111[192] = 0.0;
   out_6174181234683270111[193] = 0.0;
   out_6174181234683270111[194] = 0.0;
   out_6174181234683270111[195] = 0.0;
   out_6174181234683270111[196] = 0.0;
   out_6174181234683270111[197] = 0.0;
   out_6174181234683270111[198] = 0.0;
   out_6174181234683270111[199] = 0.0;
   out_6174181234683270111[200] = 0.0;
   out_6174181234683270111[201] = 0.0;
   out_6174181234683270111[202] = 0.0;
   out_6174181234683270111[203] = 0.0;
   out_6174181234683270111[204] = 0.0;
   out_6174181234683270111[205] = 0.0;
   out_6174181234683270111[206] = 0.0;
   out_6174181234683270111[207] = 0.0;
   out_6174181234683270111[208] = 0.0;
   out_6174181234683270111[209] = 1.0;
   out_6174181234683270111[210] = 0.0;
   out_6174181234683270111[211] = 0.0;
   out_6174181234683270111[212] = 0.0;
   out_6174181234683270111[213] = 0.0;
   out_6174181234683270111[214] = 0.0;
   out_6174181234683270111[215] = 0.0;
   out_6174181234683270111[216] = 0.0;
   out_6174181234683270111[217] = 0.0;
   out_6174181234683270111[218] = 0.0;
   out_6174181234683270111[219] = 0.0;
   out_6174181234683270111[220] = 0.0;
   out_6174181234683270111[221] = 0.0;
   out_6174181234683270111[222] = 0.0;
   out_6174181234683270111[223] = 0.0;
   out_6174181234683270111[224] = 0.0;
   out_6174181234683270111[225] = 0.0;
   out_6174181234683270111[226] = 0.0;
   out_6174181234683270111[227] = 0.0;
   out_6174181234683270111[228] = 1.0;
   out_6174181234683270111[229] = 0.0;
   out_6174181234683270111[230] = 0.0;
   out_6174181234683270111[231] = 0.0;
   out_6174181234683270111[232] = 0.0;
   out_6174181234683270111[233] = 0.0;
   out_6174181234683270111[234] = 0.0;
   out_6174181234683270111[235] = 0.0;
   out_6174181234683270111[236] = 0.0;
   out_6174181234683270111[237] = 0.0;
   out_6174181234683270111[238] = 0.0;
   out_6174181234683270111[239] = 0.0;
   out_6174181234683270111[240] = 0.0;
   out_6174181234683270111[241] = 0.0;
   out_6174181234683270111[242] = 0.0;
   out_6174181234683270111[243] = 0.0;
   out_6174181234683270111[244] = 0.0;
   out_6174181234683270111[245] = 0.0;
   out_6174181234683270111[246] = 0.0;
   out_6174181234683270111[247] = 1.0;
   out_6174181234683270111[248] = 0.0;
   out_6174181234683270111[249] = 0.0;
   out_6174181234683270111[250] = 0.0;
   out_6174181234683270111[251] = 0.0;
   out_6174181234683270111[252] = 0.0;
   out_6174181234683270111[253] = 0.0;
   out_6174181234683270111[254] = 0.0;
   out_6174181234683270111[255] = 0.0;
   out_6174181234683270111[256] = 0.0;
   out_6174181234683270111[257] = 0.0;
   out_6174181234683270111[258] = 0.0;
   out_6174181234683270111[259] = 0.0;
   out_6174181234683270111[260] = 0.0;
   out_6174181234683270111[261] = 0.0;
   out_6174181234683270111[262] = 0.0;
   out_6174181234683270111[263] = 0.0;
   out_6174181234683270111[264] = 0.0;
   out_6174181234683270111[265] = 0.0;
   out_6174181234683270111[266] = 1.0;
   out_6174181234683270111[267] = 0.0;
   out_6174181234683270111[268] = 0.0;
   out_6174181234683270111[269] = 0.0;
   out_6174181234683270111[270] = 0.0;
   out_6174181234683270111[271] = 0.0;
   out_6174181234683270111[272] = 0.0;
   out_6174181234683270111[273] = 0.0;
   out_6174181234683270111[274] = 0.0;
   out_6174181234683270111[275] = 0.0;
   out_6174181234683270111[276] = 0.0;
   out_6174181234683270111[277] = 0.0;
   out_6174181234683270111[278] = 0.0;
   out_6174181234683270111[279] = 0.0;
   out_6174181234683270111[280] = 0.0;
   out_6174181234683270111[281] = 0.0;
   out_6174181234683270111[282] = 0.0;
   out_6174181234683270111[283] = 0.0;
   out_6174181234683270111[284] = 0.0;
   out_6174181234683270111[285] = 1.0;
   out_6174181234683270111[286] = 0.0;
   out_6174181234683270111[287] = 0.0;
   out_6174181234683270111[288] = 0.0;
   out_6174181234683270111[289] = 0.0;
   out_6174181234683270111[290] = 0.0;
   out_6174181234683270111[291] = 0.0;
   out_6174181234683270111[292] = 0.0;
   out_6174181234683270111[293] = 0.0;
   out_6174181234683270111[294] = 0.0;
   out_6174181234683270111[295] = 0.0;
   out_6174181234683270111[296] = 0.0;
   out_6174181234683270111[297] = 0.0;
   out_6174181234683270111[298] = 0.0;
   out_6174181234683270111[299] = 0.0;
   out_6174181234683270111[300] = 0.0;
   out_6174181234683270111[301] = 0.0;
   out_6174181234683270111[302] = 0.0;
   out_6174181234683270111[303] = 0.0;
   out_6174181234683270111[304] = 1.0;
   out_6174181234683270111[305] = 0.0;
   out_6174181234683270111[306] = 0.0;
   out_6174181234683270111[307] = 0.0;
   out_6174181234683270111[308] = 0.0;
   out_6174181234683270111[309] = 0.0;
   out_6174181234683270111[310] = 0.0;
   out_6174181234683270111[311] = 0.0;
   out_6174181234683270111[312] = 0.0;
   out_6174181234683270111[313] = 0.0;
   out_6174181234683270111[314] = 0.0;
   out_6174181234683270111[315] = 0.0;
   out_6174181234683270111[316] = 0.0;
   out_6174181234683270111[317] = 0.0;
   out_6174181234683270111[318] = 0.0;
   out_6174181234683270111[319] = 0.0;
   out_6174181234683270111[320] = 0.0;
   out_6174181234683270111[321] = 0.0;
   out_6174181234683270111[322] = 0.0;
   out_6174181234683270111[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7324309586582217442) {
   out_7324309586582217442[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7324309586582217442[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7324309586582217442[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7324309586582217442[3] = dt*state[12] + state[3];
   out_7324309586582217442[4] = dt*state[13] + state[4];
   out_7324309586582217442[5] = dt*state[14] + state[5];
   out_7324309586582217442[6] = state[6];
   out_7324309586582217442[7] = state[7];
   out_7324309586582217442[8] = state[8];
   out_7324309586582217442[9] = state[9];
   out_7324309586582217442[10] = state[10];
   out_7324309586582217442[11] = state[11];
   out_7324309586582217442[12] = state[12];
   out_7324309586582217442[13] = state[13];
   out_7324309586582217442[14] = state[14];
   out_7324309586582217442[15] = state[15];
   out_7324309586582217442[16] = state[16];
   out_7324309586582217442[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1308578000914971504) {
   out_1308578000914971504[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1308578000914971504[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1308578000914971504[2] = 0;
   out_1308578000914971504[3] = 0;
   out_1308578000914971504[4] = 0;
   out_1308578000914971504[5] = 0;
   out_1308578000914971504[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1308578000914971504[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1308578000914971504[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1308578000914971504[9] = 0;
   out_1308578000914971504[10] = 0;
   out_1308578000914971504[11] = 0;
   out_1308578000914971504[12] = 0;
   out_1308578000914971504[13] = 0;
   out_1308578000914971504[14] = 0;
   out_1308578000914971504[15] = 0;
   out_1308578000914971504[16] = 0;
   out_1308578000914971504[17] = 0;
   out_1308578000914971504[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1308578000914971504[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1308578000914971504[20] = 0;
   out_1308578000914971504[21] = 0;
   out_1308578000914971504[22] = 0;
   out_1308578000914971504[23] = 0;
   out_1308578000914971504[24] = 0;
   out_1308578000914971504[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1308578000914971504[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1308578000914971504[27] = 0;
   out_1308578000914971504[28] = 0;
   out_1308578000914971504[29] = 0;
   out_1308578000914971504[30] = 0;
   out_1308578000914971504[31] = 0;
   out_1308578000914971504[32] = 0;
   out_1308578000914971504[33] = 0;
   out_1308578000914971504[34] = 0;
   out_1308578000914971504[35] = 0;
   out_1308578000914971504[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1308578000914971504[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1308578000914971504[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1308578000914971504[39] = 0;
   out_1308578000914971504[40] = 0;
   out_1308578000914971504[41] = 0;
   out_1308578000914971504[42] = 0;
   out_1308578000914971504[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1308578000914971504[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1308578000914971504[45] = 0;
   out_1308578000914971504[46] = 0;
   out_1308578000914971504[47] = 0;
   out_1308578000914971504[48] = 0;
   out_1308578000914971504[49] = 0;
   out_1308578000914971504[50] = 0;
   out_1308578000914971504[51] = 0;
   out_1308578000914971504[52] = 0;
   out_1308578000914971504[53] = 0;
   out_1308578000914971504[54] = 0;
   out_1308578000914971504[55] = 0;
   out_1308578000914971504[56] = 0;
   out_1308578000914971504[57] = 1;
   out_1308578000914971504[58] = 0;
   out_1308578000914971504[59] = 0;
   out_1308578000914971504[60] = 0;
   out_1308578000914971504[61] = 0;
   out_1308578000914971504[62] = 0;
   out_1308578000914971504[63] = 0;
   out_1308578000914971504[64] = 0;
   out_1308578000914971504[65] = 0;
   out_1308578000914971504[66] = dt;
   out_1308578000914971504[67] = 0;
   out_1308578000914971504[68] = 0;
   out_1308578000914971504[69] = 0;
   out_1308578000914971504[70] = 0;
   out_1308578000914971504[71] = 0;
   out_1308578000914971504[72] = 0;
   out_1308578000914971504[73] = 0;
   out_1308578000914971504[74] = 0;
   out_1308578000914971504[75] = 0;
   out_1308578000914971504[76] = 1;
   out_1308578000914971504[77] = 0;
   out_1308578000914971504[78] = 0;
   out_1308578000914971504[79] = 0;
   out_1308578000914971504[80] = 0;
   out_1308578000914971504[81] = 0;
   out_1308578000914971504[82] = 0;
   out_1308578000914971504[83] = 0;
   out_1308578000914971504[84] = 0;
   out_1308578000914971504[85] = dt;
   out_1308578000914971504[86] = 0;
   out_1308578000914971504[87] = 0;
   out_1308578000914971504[88] = 0;
   out_1308578000914971504[89] = 0;
   out_1308578000914971504[90] = 0;
   out_1308578000914971504[91] = 0;
   out_1308578000914971504[92] = 0;
   out_1308578000914971504[93] = 0;
   out_1308578000914971504[94] = 0;
   out_1308578000914971504[95] = 1;
   out_1308578000914971504[96] = 0;
   out_1308578000914971504[97] = 0;
   out_1308578000914971504[98] = 0;
   out_1308578000914971504[99] = 0;
   out_1308578000914971504[100] = 0;
   out_1308578000914971504[101] = 0;
   out_1308578000914971504[102] = 0;
   out_1308578000914971504[103] = 0;
   out_1308578000914971504[104] = dt;
   out_1308578000914971504[105] = 0;
   out_1308578000914971504[106] = 0;
   out_1308578000914971504[107] = 0;
   out_1308578000914971504[108] = 0;
   out_1308578000914971504[109] = 0;
   out_1308578000914971504[110] = 0;
   out_1308578000914971504[111] = 0;
   out_1308578000914971504[112] = 0;
   out_1308578000914971504[113] = 0;
   out_1308578000914971504[114] = 1;
   out_1308578000914971504[115] = 0;
   out_1308578000914971504[116] = 0;
   out_1308578000914971504[117] = 0;
   out_1308578000914971504[118] = 0;
   out_1308578000914971504[119] = 0;
   out_1308578000914971504[120] = 0;
   out_1308578000914971504[121] = 0;
   out_1308578000914971504[122] = 0;
   out_1308578000914971504[123] = 0;
   out_1308578000914971504[124] = 0;
   out_1308578000914971504[125] = 0;
   out_1308578000914971504[126] = 0;
   out_1308578000914971504[127] = 0;
   out_1308578000914971504[128] = 0;
   out_1308578000914971504[129] = 0;
   out_1308578000914971504[130] = 0;
   out_1308578000914971504[131] = 0;
   out_1308578000914971504[132] = 0;
   out_1308578000914971504[133] = 1;
   out_1308578000914971504[134] = 0;
   out_1308578000914971504[135] = 0;
   out_1308578000914971504[136] = 0;
   out_1308578000914971504[137] = 0;
   out_1308578000914971504[138] = 0;
   out_1308578000914971504[139] = 0;
   out_1308578000914971504[140] = 0;
   out_1308578000914971504[141] = 0;
   out_1308578000914971504[142] = 0;
   out_1308578000914971504[143] = 0;
   out_1308578000914971504[144] = 0;
   out_1308578000914971504[145] = 0;
   out_1308578000914971504[146] = 0;
   out_1308578000914971504[147] = 0;
   out_1308578000914971504[148] = 0;
   out_1308578000914971504[149] = 0;
   out_1308578000914971504[150] = 0;
   out_1308578000914971504[151] = 0;
   out_1308578000914971504[152] = 1;
   out_1308578000914971504[153] = 0;
   out_1308578000914971504[154] = 0;
   out_1308578000914971504[155] = 0;
   out_1308578000914971504[156] = 0;
   out_1308578000914971504[157] = 0;
   out_1308578000914971504[158] = 0;
   out_1308578000914971504[159] = 0;
   out_1308578000914971504[160] = 0;
   out_1308578000914971504[161] = 0;
   out_1308578000914971504[162] = 0;
   out_1308578000914971504[163] = 0;
   out_1308578000914971504[164] = 0;
   out_1308578000914971504[165] = 0;
   out_1308578000914971504[166] = 0;
   out_1308578000914971504[167] = 0;
   out_1308578000914971504[168] = 0;
   out_1308578000914971504[169] = 0;
   out_1308578000914971504[170] = 0;
   out_1308578000914971504[171] = 1;
   out_1308578000914971504[172] = 0;
   out_1308578000914971504[173] = 0;
   out_1308578000914971504[174] = 0;
   out_1308578000914971504[175] = 0;
   out_1308578000914971504[176] = 0;
   out_1308578000914971504[177] = 0;
   out_1308578000914971504[178] = 0;
   out_1308578000914971504[179] = 0;
   out_1308578000914971504[180] = 0;
   out_1308578000914971504[181] = 0;
   out_1308578000914971504[182] = 0;
   out_1308578000914971504[183] = 0;
   out_1308578000914971504[184] = 0;
   out_1308578000914971504[185] = 0;
   out_1308578000914971504[186] = 0;
   out_1308578000914971504[187] = 0;
   out_1308578000914971504[188] = 0;
   out_1308578000914971504[189] = 0;
   out_1308578000914971504[190] = 1;
   out_1308578000914971504[191] = 0;
   out_1308578000914971504[192] = 0;
   out_1308578000914971504[193] = 0;
   out_1308578000914971504[194] = 0;
   out_1308578000914971504[195] = 0;
   out_1308578000914971504[196] = 0;
   out_1308578000914971504[197] = 0;
   out_1308578000914971504[198] = 0;
   out_1308578000914971504[199] = 0;
   out_1308578000914971504[200] = 0;
   out_1308578000914971504[201] = 0;
   out_1308578000914971504[202] = 0;
   out_1308578000914971504[203] = 0;
   out_1308578000914971504[204] = 0;
   out_1308578000914971504[205] = 0;
   out_1308578000914971504[206] = 0;
   out_1308578000914971504[207] = 0;
   out_1308578000914971504[208] = 0;
   out_1308578000914971504[209] = 1;
   out_1308578000914971504[210] = 0;
   out_1308578000914971504[211] = 0;
   out_1308578000914971504[212] = 0;
   out_1308578000914971504[213] = 0;
   out_1308578000914971504[214] = 0;
   out_1308578000914971504[215] = 0;
   out_1308578000914971504[216] = 0;
   out_1308578000914971504[217] = 0;
   out_1308578000914971504[218] = 0;
   out_1308578000914971504[219] = 0;
   out_1308578000914971504[220] = 0;
   out_1308578000914971504[221] = 0;
   out_1308578000914971504[222] = 0;
   out_1308578000914971504[223] = 0;
   out_1308578000914971504[224] = 0;
   out_1308578000914971504[225] = 0;
   out_1308578000914971504[226] = 0;
   out_1308578000914971504[227] = 0;
   out_1308578000914971504[228] = 1;
   out_1308578000914971504[229] = 0;
   out_1308578000914971504[230] = 0;
   out_1308578000914971504[231] = 0;
   out_1308578000914971504[232] = 0;
   out_1308578000914971504[233] = 0;
   out_1308578000914971504[234] = 0;
   out_1308578000914971504[235] = 0;
   out_1308578000914971504[236] = 0;
   out_1308578000914971504[237] = 0;
   out_1308578000914971504[238] = 0;
   out_1308578000914971504[239] = 0;
   out_1308578000914971504[240] = 0;
   out_1308578000914971504[241] = 0;
   out_1308578000914971504[242] = 0;
   out_1308578000914971504[243] = 0;
   out_1308578000914971504[244] = 0;
   out_1308578000914971504[245] = 0;
   out_1308578000914971504[246] = 0;
   out_1308578000914971504[247] = 1;
   out_1308578000914971504[248] = 0;
   out_1308578000914971504[249] = 0;
   out_1308578000914971504[250] = 0;
   out_1308578000914971504[251] = 0;
   out_1308578000914971504[252] = 0;
   out_1308578000914971504[253] = 0;
   out_1308578000914971504[254] = 0;
   out_1308578000914971504[255] = 0;
   out_1308578000914971504[256] = 0;
   out_1308578000914971504[257] = 0;
   out_1308578000914971504[258] = 0;
   out_1308578000914971504[259] = 0;
   out_1308578000914971504[260] = 0;
   out_1308578000914971504[261] = 0;
   out_1308578000914971504[262] = 0;
   out_1308578000914971504[263] = 0;
   out_1308578000914971504[264] = 0;
   out_1308578000914971504[265] = 0;
   out_1308578000914971504[266] = 1;
   out_1308578000914971504[267] = 0;
   out_1308578000914971504[268] = 0;
   out_1308578000914971504[269] = 0;
   out_1308578000914971504[270] = 0;
   out_1308578000914971504[271] = 0;
   out_1308578000914971504[272] = 0;
   out_1308578000914971504[273] = 0;
   out_1308578000914971504[274] = 0;
   out_1308578000914971504[275] = 0;
   out_1308578000914971504[276] = 0;
   out_1308578000914971504[277] = 0;
   out_1308578000914971504[278] = 0;
   out_1308578000914971504[279] = 0;
   out_1308578000914971504[280] = 0;
   out_1308578000914971504[281] = 0;
   out_1308578000914971504[282] = 0;
   out_1308578000914971504[283] = 0;
   out_1308578000914971504[284] = 0;
   out_1308578000914971504[285] = 1;
   out_1308578000914971504[286] = 0;
   out_1308578000914971504[287] = 0;
   out_1308578000914971504[288] = 0;
   out_1308578000914971504[289] = 0;
   out_1308578000914971504[290] = 0;
   out_1308578000914971504[291] = 0;
   out_1308578000914971504[292] = 0;
   out_1308578000914971504[293] = 0;
   out_1308578000914971504[294] = 0;
   out_1308578000914971504[295] = 0;
   out_1308578000914971504[296] = 0;
   out_1308578000914971504[297] = 0;
   out_1308578000914971504[298] = 0;
   out_1308578000914971504[299] = 0;
   out_1308578000914971504[300] = 0;
   out_1308578000914971504[301] = 0;
   out_1308578000914971504[302] = 0;
   out_1308578000914971504[303] = 0;
   out_1308578000914971504[304] = 1;
   out_1308578000914971504[305] = 0;
   out_1308578000914971504[306] = 0;
   out_1308578000914971504[307] = 0;
   out_1308578000914971504[308] = 0;
   out_1308578000914971504[309] = 0;
   out_1308578000914971504[310] = 0;
   out_1308578000914971504[311] = 0;
   out_1308578000914971504[312] = 0;
   out_1308578000914971504[313] = 0;
   out_1308578000914971504[314] = 0;
   out_1308578000914971504[315] = 0;
   out_1308578000914971504[316] = 0;
   out_1308578000914971504[317] = 0;
   out_1308578000914971504[318] = 0;
   out_1308578000914971504[319] = 0;
   out_1308578000914971504[320] = 0;
   out_1308578000914971504[321] = 0;
   out_1308578000914971504[322] = 0;
   out_1308578000914971504[323] = 1;
}
void h_4(double *state, double *unused, double *out_5274511212490178907) {
   out_5274511212490178907[0] = state[6] + state[9];
   out_5274511212490178907[1] = state[7] + state[10];
   out_5274511212490178907[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5420020232628557504) {
   out_5420020232628557504[0] = 0;
   out_5420020232628557504[1] = 0;
   out_5420020232628557504[2] = 0;
   out_5420020232628557504[3] = 0;
   out_5420020232628557504[4] = 0;
   out_5420020232628557504[5] = 0;
   out_5420020232628557504[6] = 1;
   out_5420020232628557504[7] = 0;
   out_5420020232628557504[8] = 0;
   out_5420020232628557504[9] = 1;
   out_5420020232628557504[10] = 0;
   out_5420020232628557504[11] = 0;
   out_5420020232628557504[12] = 0;
   out_5420020232628557504[13] = 0;
   out_5420020232628557504[14] = 0;
   out_5420020232628557504[15] = 0;
   out_5420020232628557504[16] = 0;
   out_5420020232628557504[17] = 0;
   out_5420020232628557504[18] = 0;
   out_5420020232628557504[19] = 0;
   out_5420020232628557504[20] = 0;
   out_5420020232628557504[21] = 0;
   out_5420020232628557504[22] = 0;
   out_5420020232628557504[23] = 0;
   out_5420020232628557504[24] = 0;
   out_5420020232628557504[25] = 1;
   out_5420020232628557504[26] = 0;
   out_5420020232628557504[27] = 0;
   out_5420020232628557504[28] = 1;
   out_5420020232628557504[29] = 0;
   out_5420020232628557504[30] = 0;
   out_5420020232628557504[31] = 0;
   out_5420020232628557504[32] = 0;
   out_5420020232628557504[33] = 0;
   out_5420020232628557504[34] = 0;
   out_5420020232628557504[35] = 0;
   out_5420020232628557504[36] = 0;
   out_5420020232628557504[37] = 0;
   out_5420020232628557504[38] = 0;
   out_5420020232628557504[39] = 0;
   out_5420020232628557504[40] = 0;
   out_5420020232628557504[41] = 0;
   out_5420020232628557504[42] = 0;
   out_5420020232628557504[43] = 0;
   out_5420020232628557504[44] = 1;
   out_5420020232628557504[45] = 0;
   out_5420020232628557504[46] = 0;
   out_5420020232628557504[47] = 1;
   out_5420020232628557504[48] = 0;
   out_5420020232628557504[49] = 0;
   out_5420020232628557504[50] = 0;
   out_5420020232628557504[51] = 0;
   out_5420020232628557504[52] = 0;
   out_5420020232628557504[53] = 0;
}
void h_10(double *state, double *unused, double *out_5708186129868046088) {
   out_5708186129868046088[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5708186129868046088[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5708186129868046088[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3000306243932108488) {
   out_3000306243932108488[0] = 0;
   out_3000306243932108488[1] = 9.8100000000000005*cos(state[1]);
   out_3000306243932108488[2] = 0;
   out_3000306243932108488[3] = 0;
   out_3000306243932108488[4] = -state[8];
   out_3000306243932108488[5] = state[7];
   out_3000306243932108488[6] = 0;
   out_3000306243932108488[7] = state[5];
   out_3000306243932108488[8] = -state[4];
   out_3000306243932108488[9] = 0;
   out_3000306243932108488[10] = 0;
   out_3000306243932108488[11] = 0;
   out_3000306243932108488[12] = 1;
   out_3000306243932108488[13] = 0;
   out_3000306243932108488[14] = 0;
   out_3000306243932108488[15] = 1;
   out_3000306243932108488[16] = 0;
   out_3000306243932108488[17] = 0;
   out_3000306243932108488[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3000306243932108488[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3000306243932108488[20] = 0;
   out_3000306243932108488[21] = state[8];
   out_3000306243932108488[22] = 0;
   out_3000306243932108488[23] = -state[6];
   out_3000306243932108488[24] = -state[5];
   out_3000306243932108488[25] = 0;
   out_3000306243932108488[26] = state[3];
   out_3000306243932108488[27] = 0;
   out_3000306243932108488[28] = 0;
   out_3000306243932108488[29] = 0;
   out_3000306243932108488[30] = 0;
   out_3000306243932108488[31] = 1;
   out_3000306243932108488[32] = 0;
   out_3000306243932108488[33] = 0;
   out_3000306243932108488[34] = 1;
   out_3000306243932108488[35] = 0;
   out_3000306243932108488[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3000306243932108488[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3000306243932108488[38] = 0;
   out_3000306243932108488[39] = -state[7];
   out_3000306243932108488[40] = state[6];
   out_3000306243932108488[41] = 0;
   out_3000306243932108488[42] = state[4];
   out_3000306243932108488[43] = -state[3];
   out_3000306243932108488[44] = 0;
   out_3000306243932108488[45] = 0;
   out_3000306243932108488[46] = 0;
   out_3000306243932108488[47] = 0;
   out_3000306243932108488[48] = 0;
   out_3000306243932108488[49] = 0;
   out_3000306243932108488[50] = 1;
   out_3000306243932108488[51] = 0;
   out_3000306243932108488[52] = 0;
   out_3000306243932108488[53] = 1;
}
void h_13(double *state, double *unused, double *out_8062490707768129845) {
   out_8062490707768129845[0] = state[3];
   out_8062490707768129845[1] = state[4];
   out_8062490707768129845[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2207746407296224703) {
   out_2207746407296224703[0] = 0;
   out_2207746407296224703[1] = 0;
   out_2207746407296224703[2] = 0;
   out_2207746407296224703[3] = 1;
   out_2207746407296224703[4] = 0;
   out_2207746407296224703[5] = 0;
   out_2207746407296224703[6] = 0;
   out_2207746407296224703[7] = 0;
   out_2207746407296224703[8] = 0;
   out_2207746407296224703[9] = 0;
   out_2207746407296224703[10] = 0;
   out_2207746407296224703[11] = 0;
   out_2207746407296224703[12] = 0;
   out_2207746407296224703[13] = 0;
   out_2207746407296224703[14] = 0;
   out_2207746407296224703[15] = 0;
   out_2207746407296224703[16] = 0;
   out_2207746407296224703[17] = 0;
   out_2207746407296224703[18] = 0;
   out_2207746407296224703[19] = 0;
   out_2207746407296224703[20] = 0;
   out_2207746407296224703[21] = 0;
   out_2207746407296224703[22] = 1;
   out_2207746407296224703[23] = 0;
   out_2207746407296224703[24] = 0;
   out_2207746407296224703[25] = 0;
   out_2207746407296224703[26] = 0;
   out_2207746407296224703[27] = 0;
   out_2207746407296224703[28] = 0;
   out_2207746407296224703[29] = 0;
   out_2207746407296224703[30] = 0;
   out_2207746407296224703[31] = 0;
   out_2207746407296224703[32] = 0;
   out_2207746407296224703[33] = 0;
   out_2207746407296224703[34] = 0;
   out_2207746407296224703[35] = 0;
   out_2207746407296224703[36] = 0;
   out_2207746407296224703[37] = 0;
   out_2207746407296224703[38] = 0;
   out_2207746407296224703[39] = 0;
   out_2207746407296224703[40] = 0;
   out_2207746407296224703[41] = 1;
   out_2207746407296224703[42] = 0;
   out_2207746407296224703[43] = 0;
   out_2207746407296224703[44] = 0;
   out_2207746407296224703[45] = 0;
   out_2207746407296224703[46] = 0;
   out_2207746407296224703[47] = 0;
   out_2207746407296224703[48] = 0;
   out_2207746407296224703[49] = 0;
   out_2207746407296224703[50] = 0;
   out_2207746407296224703[51] = 0;
   out_2207746407296224703[52] = 0;
   out_2207746407296224703[53] = 0;
}
void h_14(double *state, double *unused, double *out_4471759381132971331) {
   out_4471759381132971331[0] = state[6];
   out_4471759381132971331[1] = state[7];
   out_4471759381132971331[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1456779376289072975) {
   out_1456779376289072975[0] = 0;
   out_1456779376289072975[1] = 0;
   out_1456779376289072975[2] = 0;
   out_1456779376289072975[3] = 0;
   out_1456779376289072975[4] = 0;
   out_1456779376289072975[5] = 0;
   out_1456779376289072975[6] = 1;
   out_1456779376289072975[7] = 0;
   out_1456779376289072975[8] = 0;
   out_1456779376289072975[9] = 0;
   out_1456779376289072975[10] = 0;
   out_1456779376289072975[11] = 0;
   out_1456779376289072975[12] = 0;
   out_1456779376289072975[13] = 0;
   out_1456779376289072975[14] = 0;
   out_1456779376289072975[15] = 0;
   out_1456779376289072975[16] = 0;
   out_1456779376289072975[17] = 0;
   out_1456779376289072975[18] = 0;
   out_1456779376289072975[19] = 0;
   out_1456779376289072975[20] = 0;
   out_1456779376289072975[21] = 0;
   out_1456779376289072975[22] = 0;
   out_1456779376289072975[23] = 0;
   out_1456779376289072975[24] = 0;
   out_1456779376289072975[25] = 1;
   out_1456779376289072975[26] = 0;
   out_1456779376289072975[27] = 0;
   out_1456779376289072975[28] = 0;
   out_1456779376289072975[29] = 0;
   out_1456779376289072975[30] = 0;
   out_1456779376289072975[31] = 0;
   out_1456779376289072975[32] = 0;
   out_1456779376289072975[33] = 0;
   out_1456779376289072975[34] = 0;
   out_1456779376289072975[35] = 0;
   out_1456779376289072975[36] = 0;
   out_1456779376289072975[37] = 0;
   out_1456779376289072975[38] = 0;
   out_1456779376289072975[39] = 0;
   out_1456779376289072975[40] = 0;
   out_1456779376289072975[41] = 0;
   out_1456779376289072975[42] = 0;
   out_1456779376289072975[43] = 0;
   out_1456779376289072975[44] = 1;
   out_1456779376289072975[45] = 0;
   out_1456779376289072975[46] = 0;
   out_1456779376289072975[47] = 0;
   out_1456779376289072975[48] = 0;
   out_1456779376289072975[49] = 0;
   out_1456779376289072975[50] = 0;
   out_1456779376289072975[51] = 0;
   out_1456779376289072975[52] = 0;
   out_1456779376289072975[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6229004230267029840) {
  err_fun(nom_x, delta_x, out_6229004230267029840);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7305334829560631632) {
  inv_err_fun(nom_x, true_x, out_7305334829560631632);
}
void pose_H_mod_fun(double *state, double *out_6174181234683270111) {
  H_mod_fun(state, out_6174181234683270111);
}
void pose_f_fun(double *state, double dt, double *out_7324309586582217442) {
  f_fun(state,  dt, out_7324309586582217442);
}
void pose_F_fun(double *state, double dt, double *out_1308578000914971504) {
  F_fun(state,  dt, out_1308578000914971504);
}
void pose_h_4(double *state, double *unused, double *out_5274511212490178907) {
  h_4(state, unused, out_5274511212490178907);
}
void pose_H_4(double *state, double *unused, double *out_5420020232628557504) {
  H_4(state, unused, out_5420020232628557504);
}
void pose_h_10(double *state, double *unused, double *out_5708186129868046088) {
  h_10(state, unused, out_5708186129868046088);
}
void pose_H_10(double *state, double *unused, double *out_3000306243932108488) {
  H_10(state, unused, out_3000306243932108488);
}
void pose_h_13(double *state, double *unused, double *out_8062490707768129845) {
  h_13(state, unused, out_8062490707768129845);
}
void pose_H_13(double *state, double *unused, double *out_2207746407296224703) {
  H_13(state, unused, out_2207746407296224703);
}
void pose_h_14(double *state, double *unused, double *out_4471759381132971331) {
  h_14(state, unused, out_4471759381132971331);
}
void pose_H_14(double *state, double *unused, double *out_1456779376289072975) {
  H_14(state, unused, out_1456779376289072975);
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
