include <_utils/knurled_cylinder.scad>

$fa = 1;
$fs = 0.15;

layer_height = 0.2;
bottom_solid_layers = 3;
bottom_solid = layer_height*bottom_solid_layers;

knob_radius = 8;
knob_height = 14.6;
knob_border = 2;

knob_bevel = 0;
knob_knurl_width = 2;
knob_knurl_height = 3;
knob_knurl_depth = 0.5;

knob_top_clearance = 1.6; // Depth of the hole on the open side

shaft_height = knob_height-knob_top_clearance-bottom_solid;
d_tolerance = 0.15; // The tolerance for the D hole for the encoder
d_cut = 1.5; // Amount that should be cut for the D hole for the encoder


difference(){
    //Body
    translate([0,0, knob_border/2])
        union(){
            cylinder(r=knob_radius, h=knob_border, center=true);

            translate([0, 0, knob_border/2])
                knurled_cylinder(height=knob_height-(2*knob_border), diameter=knob_radius*2-knob_knurl_depth, bevel=knob_bevel, knurl_depth=knob_knurl_depth, knurl_width=knob_knurl_width, knurl_height=knob_knurl_height);

            //Rounded top edge
            hull() {
                translate([0, 0, knob_height-1.5*knob_border]) cylinder(r=knob_radius, h=knob_border/2);
                translate([0,0,knob_height-knob_border])rotate_extrude() translate([knob_radius-1, 0]) circle(r=1);
            }
        }
    //Hole in the knob
    translate([0,0, -knob_height-0.001 + knob_top_clearance])
        cylinder(r=knob_radius-2, h=knob_height+0.001);

    //D cutout for encoder
    translate([0,0, knob_height-(shaft_height/2)-bottom_solid-0.001])
    difference(){
        cylinder(r=3 + d_tolerance/2, h=shaft_height+0.001, center=true);
        translate([-(d_cut+4.5/2 + d_tolerance), 0, 0]) 
            cube([4.5, 10, shaft_height+0.002], center=true);
    }
}





