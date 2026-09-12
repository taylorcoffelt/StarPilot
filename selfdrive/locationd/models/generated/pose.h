#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2603305221510379343);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4906336809504339286);
void pose_H_mod_fun(double *state, double *out_5030482369160908110);
void pose_f_fun(double *state, double dt, double *out_1235990561508542419);
void pose_F_fun(double *state, double dt, double *out_1393525693373603519);
void pose_h_4(double *state, double *unused, double *out_1733375464843140313);
void pose_H_4(double *state, double *unused, double *out_6850181095067204971);
void pose_h_10(double *state, double *unused, double *out_1803459148168206843);
void pose_H_10(double *state, double *unused, double *out_1870184976953523917);
void pose_h_13(double *state, double *unused, double *out_5196198746117623945);
void pose_H_13(double *state, double *unused, double *out_3637907269734872170);
void pose_h_14(double *state, double *unused, double *out_2301659273555299219);
void pose_H_14(double *state, double *unused, double *out_2886940238727720442);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}