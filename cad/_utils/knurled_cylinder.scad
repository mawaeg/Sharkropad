/*
 * Knurled surface library
 * License: Public domain
 *
 * Originally written by aubenc @ Thingiverse: https://www.thingiverse.com/thing:32122
 * Remixed by cnt @ Thingiverse: https://www.thingiverse.com/thing:4146258
 */

module knurled_cylinder(
    height=12,          // knurled cylinder height
    diameter=25,        // knurled cylinder outer diameter
    knurl_width=3,      // knurling polyhedron width
    knurl_height=4,     // knurling polyhedron height
    knurl_depth=1.5,    // knurling polyhedron depth
    bevel=2,            // bevel height
    smooth=0            // percentage between 0 and 100
) {
    cord = (diameter + knurl_depth + knurl_depth * smooth / 100) / 2;
    cird = cord - knurl_depth;
    cfn = round(2 * cird * PI / knurl_width);
    clf = 360 / cfn;
    crn = ceil(height / knurl_height);

    if (bevel < 0) {
        shape(bevel, cird+knurl_depth*smooth/100, cord, cfn*4, height);
        translate([0,0,-(crn*knurl_height-height)/2])
        knurled_finish(cord, cird, clf, knurl_height, cfn, crn);
    } else {
        intersection() {
            if (bevel == 0) {
                cylinder(h=height, r=cord-knurl_depth*smooth/100, $fn=2*cfn, center=false);
            } else {
                shape(bevel, cird, cord-knurl_depth*smooth/100, cfn*4, height);
            }
            translate([0,0,-(crn*knurl_height-height)/2])
            knurled_finish(cord, cird, clf, knurl_height, cfn, crn);
        }
    }
}

module shape(hsh, ird, ord, fn4, hg)
{
    x0 = 0;
    x1 = hsh > 0 ? ird : ord;
    x2 = hsh > 0 ? ord : ird;
    y0 = -0.1;
    y1 = 0;
    y2 = abs(hsh);
    y3 = hg - abs(hsh);
    y4 = hg;
    y5 = hg + 0.1;
    rotate_extrude(convexity=10, $fn=fn4)
    polygon(points=(
        hsh >= 0
        ? [[x0,y1], [x1,y1], [x2,y2] ,[x2,y3], [x1,y4], [x0,y4]]
        : [[x0,y0], [x1,y0], [x1,y1], [x2,y2], [x2,y3], [x1,y4], [x1,y5], [x0,y5]]
    ));
}

module knurled_finish(ord, ird, lf, sh, fn, rn)
{
    for(j = [0:rn - 1]) {
        h0 = sh * j;
        h1 = sh * (j + 1/2);
        h2 = sh * (j+1);
        for(i = [0:fn - 1]) {
            lf0 = lf * i;
            lf1 = lf * (i + 1/2);
            lf2 = lf * (i + 1);
            polyhedron(
                points=[
                     [0, 0, h0],
                     [ord*cos(lf0), ord*sin(lf0), h0],
                     [ird*cos(lf1), ird*sin(lf1), h0],
                     [ord*cos(lf2), ord*sin(lf2), h0],

                     [ird*cos(lf0), ird*sin(lf0), h1],
                     [ord*cos(lf1), ord*sin(lf1), h1],
                     [ird*cos(lf2), ird*sin(lf2), h1],

                     [0, 0, h2],
                     [ord*cos(lf0), ord*sin(lf0), h2],
                     [ird*cos(lf1), ird*sin(lf1), h2],
                     [ord*cos(lf2), ord*sin(lf2), h2]
                ],
                faces=[
                     [0,1,2], [2,3,0],
                     [1,0,4], [4,0,7], [7,8,4],
                     [8,7,9], [10,9,7],
                     [10,7,6], [6,7,0], [3,6,0],
                     [2,1,4], [3,2,6], [10,6,9], [8,9,4],
                     [4,5,2], [2,5,6], [6,5,9], [9,5,4]
                ],
                convexity=5);
         }
    }
}