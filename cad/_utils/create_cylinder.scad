module create_cylinder(h, r, translate_z){
for(i = [-1:2:1])
for(j = [-1:2:1])
    translate([i*38.814, j*40.64, translate_z])
        cylinder(h=h, r=r, center=true); 
}