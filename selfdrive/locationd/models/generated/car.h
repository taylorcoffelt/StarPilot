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
void car_err_fun(double *nom_x, double *delta_x, double *out_7342129885693953568);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6095977331238334881);
void car_H_mod_fun(double *state, double *out_2773459854461216325);
void car_f_fun(double *state, double dt, double *out_2158694114114484229);
void car_F_fun(double *state, double dt, double *out_5245282587456863723);
void car_h_25(double *state, double *unused, double *out_5698923208340302373);
void car_H_25(double *state, double *unused, double *out_2268125412260919613);
void car_h_24(double *state, double *unused, double *out_3582538229922843902);
void car_H_24(double *state, double *unused, double *out_8469158092112081039);
void car_h_30(double *state, double *unused, double *out_4984555608548576802);
void car_H_30(double *state, double *unused, double *out_2397464359404159683);
void car_h_26(double *state, double *unused, double *out_6459425761367909035);
void car_H_26(double *state, double *unused, double *out_1611271348150607709);
void car_h_27(double *state, double *unused, double *out_3765851693362408478);
void car_H_27(double *state, double *unused, double *out_4572227671204584594);
void car_h_29(double *state, double *unused, double *out_8460515197500129169);
void car_H_29(double *state, double *unused, double *out_1887233015089767499);
void car_h_28(double *state, double *unused, double *out_8767524961023254123);
void car_H_28(double *state, double *unused, double *out_76397256475558752);
void car_h_31(double *state, double *unused, double *out_6159992938892954080);
void car_H_31(double *state, double *unused, double *out_2237479450383959185);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}