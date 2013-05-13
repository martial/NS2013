var TRAME_VAR= Animation.extend({

    setup: function (s) {

        println("-- TRAME_VAR.js -- ");

        this._super();





    },

    update: function (s) {
    
    var speed = speedPct*-90;
 
setOrientation (s,0,0,-90,speed)
setOrientation (s,1,0,-90,speed)
setOrientation (s,2,0,-90,speed)
setOrientation (s,3,0,-90,speed)
lookAt (s,4,-500,-500,speed)
lookAt (s,5,-400,-350,speed)
lookAt (s,6,-250,-200,speed)
lookAt (s,7,-70,-100,speed)
lookAt (s,8,70,-100,speed)
lookAt (s,9,250,-200,speed)
lookAt (s,10,400,-350,speed)
lookAt (s,11,500,-500,speed)
setOrientation (s,12,0,-90,speed)
setOrientation (s,13,0,-90,speed)
setOrientation (s,14,0,-90,speed)
setOrientation (s,15,0,-90,speed)



setOrientation (s,16,0,90,speed)
setOrientation (s,17,0,90,speed)
setOrientation (s,18,0,90,speed)
setOrientation (s,19,0,90,speed)
lookAt (s,20,-500,500,speed)
lookAt (s,21,-400,350,speed)
lookAt (s,22,-250,200,speed)
lookAt (s,23,-70,100,speed)
lookAt (s,24,70,100,speed)
lookAt (s,25,250,200,speed)
lookAt (s,26,400,350,speed)
lookAt (s,27,500,500,speed)
setOrientation (s,28,0,90,speed)
setOrientation (s,29,0,90,speed)
setOrientation (s,30,0,90,speed)
setOrientation (s,31,0,90,speed)




    }
});




new TRAME_VAR();

