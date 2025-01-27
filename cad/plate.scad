hole_gap = 5.05;
hole_size = 14;
plate_height = 1.49;
plate_length = 79.15;
plate_width = 60.1;


difference(){
//Base
cube([plate_length, plate_width, plate_height], center=true);

//Rows
for(k = [-1:1:1]){
    //Columns
    for(i = [-1:2:1]){
    for(j = [0:1:1]){
        translate([i*((j*14+(0.5+j)*hole_gap)+hole_size/2), k*(hole_size+hole_gap), 0])
            cube([hole_size, hole_size, plate_height + 0.001], center=true);
    }
    }
}

//Edges(for the screws)
for( r = [-1:2:1])
translate([r*(plate_length/2), -(plate_width/2), 0])
rotate([0,0, r*45])
cube([hole_size/2, hole_size/2, plate_height+ 0.001], center=true);
}