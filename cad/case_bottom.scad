include <_utils/rounded_cube.scad>
include <_utils/create_cylinder.scad>
include <_utils/usb_c_cutout.scad>

$fa = 1;
$fs = 0.15;

//Base
base_x = 91.82;
base_y = 95.63;
base_z = 6;
wall_thickness = 3;
outer_radius = 6.540;
inner_radius = outer_radius-wall_thickness;
cylinder_h = 1;

//Screwholes
outer_screw_hole = 2.35;
inner_screw_hole = 1.25;

//USB-C cutout
usbc_depth= 4;
magic_port_location = 20.3;
usbc_port_z_translation = 3;


module base(){
union(){
    create_cylinder(5.001, outer_screw_hole, 2.5-0.001);
    difference(){
        rounded_cube(base_x, base_y, base_z, outer_radius, cylinder_h);

        translate([0,0,1.5+0.001])
        rounded_cube(base_x-(wall_thickness*2), base_y-(wall_thickness*2), base_z/2+0.001, inner_radius, cylinder_h);
    }
}
}

difference(){ 
    base();
    // Hole for the screw
    create_cylinder(10, inner_screw_hole, 1);   
    // Hole for the screwhead
    create_cylinder(2.001, 2.35, -2.001);
    usb_c_cutout(magic_port_location, base_y/2, usbc_port_z_translation, usbc_depth);
}