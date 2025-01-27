module rounded_cube(x, y, z, r, h){
    minkowski()
    {
      cube([x-r*2, y-r*2, z-h], center=true);
      cylinder(r=r,h=h,center=true);
    }
}