include <_utils/rounded_cube.scad>
include <_utils/create_cylinder.scad>
include <_utils/usb_c_cutout.scad>

$fa = 1;
$fs = 0.15;

//Base
base_x = 94.82;
base_y = 98.63;
base_z = 16;
wall_thickness = 5.5;
outer_radius = 8.040;
inner_radius = outer_radius - wall_thickness;
cylinder_h = 1;

//Keycap_hole
keycap_x = 76.82;
keycap_y = 57.67;
keycap_y_border_dist = 12.86;

//Oled_hole (cutout to not show the edges of the oled and hole for the display)
oled_cutout_x = 40;
oled_hole_x = 28;
oled_y = 12;
oled_cutout_x_border_dist = 12.4;
oled_y_border_dist = 13.9;
oled_hole_x_border_dist = 18.4;

//Encoder_holes (cutout to make encoder clickable and hole for the shaft of the encoder)
encoder_cutout_r = 8.1;
encoder_cutout_x_border_dist = 10.1;
encoder_cutout_y_border_dist = 11.2;
encoder_hole_r = 5;
encoder_hole_x_border_dist = 13.2;
encoder_hole_y_border_dist = 14.3;

//Wall modifier
wall_mod_1_sub = 3.046;
wall_mod_2_sub = 9;

//USB-C cutout
usbc_depth= 7;
magic_port_location = 21.811;
usbc_translate_z = 7.3;



//Heat Insert holes
difference(){
create_cylinder(9, 3.6, -0.5);
create_cylinder(9, 2.001, -0.5+0.001);
}

difference(){
//Base
rounded_cube(base_x, base_y, base_z, outer_radius, cylinder_h);
translate([0,0,3+0.001])
rounded_cube(base_x-(wall_thickness*2), base_y-(wall_thickness*2), base_z, inner_radius, cylinder_h);
    
//Keycap_hole
translate([0,base_y/2-keycap_y/2-keycap_y_border_dist, -base_z/2+1.5])
cube([keycap_x, keycap_y, 3.004], center=true);

//Oled_hole
translate([-(base_x/2-oled_cutout_x/2-oled_cutout_x_border_dist),-(base_y/2-oled_y/2-oled_y_border_dist),-base_z/2+3.5])
cube([oled_cutout_x, oled_y, 3.004], center=true);
translate([-(base_x/2-oled_hole_x/2-oled_hole_x_border_dist),-(base_y/2-oled_y/2-oled_y_border_dist),-base_z/2+1.5])
cube([oled_hole_x, oled_y, 3.004], center=true);

//Encoder_hole
translate([base_x/2-encoder_cutout_r-encoder_cutout_x_border_dist,-(base_y/2-encoder_cutout_r-encoder_cutout_y_border_dist),-base_z/2+1.5-2])
cylinder(h=3.004, r=encoder_cutout_r, center=true);
translate([base_x/2-encoder_hole_r-encoder_hole_x_border_dist,-(base_y/2-encoder_hole_r-encoder_hole_y_border_dist),-base_z/2+1.5])
cylinder(h=3.004, r=encoder_hole_r, center=true);

//Wall modifier 1
translate([0,0,base_z/2+15.4/2-0.3]) //For some reason we ned -0.3 here?
rounded_cube(base_x-wall_mod_1_sub, base_y-wall_mod_1_sub, base_z, 6.64, cylinder_h);
//Wall modifier 2
translate([0,0,base_z/2+12/2-2])
rounded_cube(base_x-wall_mod_2_sub, base_y-wall_mod_2_sub, base_z, 3.54, cylinder_h);

//USB-C cutout
usb_c_cutout(magic_port_location, -(base_y/2)+6, usbc_translate_z, usbc_depth);
}