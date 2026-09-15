#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6229004230267029840);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7305334829560631632);
void pose_H_mod_fun(double *state, double *out_6174181234683270111);
void pose_f_fun(double *state, double dt, double *out_7324309586582217442);
void pose_F_fun(double *state, double dt, double *out_1308578000914971504);
void pose_h_4(double *state, double *unused, double *out_5274511212490178907);
void pose_H_4(double *state, double *unused, double *out_5420020232628557504);
void pose_h_10(double *state, double *unused, double *out_5708186129868046088);
void pose_H_10(double *state, double *unused, double *out_3000306243932108488);
void pose_h_13(double *state, double *unused, double *out_8062490707768129845);
void pose_H_13(double *state, double *unused, double *out_2207746407296224703);
void pose_h_14(double *state, double *unused, double *out_4471759381132971331);
void pose_H_14(double *state, double *unused, double *out_1456779376289072975);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}