println("-- config.js.js -- ");

/*

DMX1, DMX2, USB1, USB2

 */

setDMXUSBPorts(0, 0, 0, 3);



// adapt fine tilt fin pan

setFinePanTilt(2,0,-3);
setFinePanTilt(3,0,-4);
setFinePanTilt(4,0,0);
setFinePanTilt(5,0,-4);
setFinePanTilt(6,0,-4);
setFinePanTilt(7,0,-4);
setFinePanTilt(8,0,-3);
setFinePanTilt(9,0,-2);
setFinePanTilt(10,0,-3);
setFinePanTilt(11,0,0);
setFinePanTilt(12,0,-8);

setFinePanTilt(13,0,-4);
setFinePanTilt(14,0,-5);
setFinePanTilt(15,0,-4);



//for ( var i=0; i<32; i++)
    //setFinePanTilt(i, 0,0);



//setFinePos(0, 0, 0);



// adapth depth
//println(depth);

depth               = getDepth();
depth -= 100;

