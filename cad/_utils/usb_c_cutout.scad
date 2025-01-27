//USB-C cutout
usbc_cylinder_radius = 4;
usbc_cylinders_distance = 6;
usbc_port_z_translation = 3;

module usb_c_cutout(magic_port_location, translate_y, translate_z, depth){
translate([-base_x/2+magic_port_location, translate_y, translate_z])
rotate([90, 0, 0])
hull(){
    cylinder(h=depth, r=usbc_cylinder_radius);
    translate([usbc_cylinders_distance,0,0])
    cylinder(h=depth, r=usbc_cylinder_radius);
}
}