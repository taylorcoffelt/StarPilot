#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7499019697074073600);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8422684140360355869);
void car_H_mod_fun(double *state, double *out_6196860334201773793);
void car_f_fun(double *state, double dt, double *out_6277255670269225220);
void car_F_fun(double *state, double dt, double *out_7160284402765973969);
void car_h_25(double *state, double *unused, double *out_8149413165682410599);
void car_H_25(double *state, double *unused, double *out_1724477698772086012);
void car_h_24(double *state, double *unused, double *out_3520377357547632824);
void car_H_24(double *state, double *unused, double *out_8378683156880271769);
void car_h_30(double *state, double *unused, double *out_8424607227966916488);
void car_H_30(double *state, double *unused, double *out_2803218631355522186);
void car_h_26(double *state, double *unused, double *out_7417731524933937477);
void car_H_26(double *state, double *unused, double *out_2017025620101970212);
void car_h_27(double *state, double *unused, double *out_5071423692191816070);
void car_H_27(double *state, double *unused, double *out_4977981943155947097);
void car_h_29(double *state, double *unused, double *out_5020463578081789483);
void car_H_29(double *state, double *unused, double *out_2292987287041130002);
void car_h_28(double *state, double *unused, double *out_3591495587617469110);
void car_H_28(double *state, double *unused, double *out_7375386304110660576);
void car_h_31(double *state, double *unused, double *out_4511963637428388249);
void car_H_31(double *state, double *unused, double *out_2643233722335321688);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}