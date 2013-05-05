var PHENIX = Animation.extend({

    setup: function (s) {

        println("-- PHENIX.js -- ");

        this._super();





    },

    update: function (s) {
    
//this.z = 0;
//this.z ++;
//var pct= 0,5+math.cos(this.z/100)*0,5;
//println(pct)
	//gauche
	
        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i];

            var currentPos  = getSharpyPos(s, i);
            //var nextPos     = getSharpyPos(s, i+2);



            //lookAt(s, index, nextPos.x, nextPos.y, depth);
            lookAt(s, nextIndex, currentPos.x, currentPos.y, depth);

}

setOrientation(s,17,0,-90,90);
setOrientation(s,19,0,-90,90);
setOrientation(s,21,0,-90,90);
setOrientation(s,23,0,-90,90);
setOrientation(s,25,0,-90,90);
setOrientation(s,27,0,-90,90);
setOrientation(s,29,0,-90,90);
setOrientation(s,31,0,-90,90);
        //setOrientation(s, 8, 0,0,-1  );
        //setBrightness   (s, 8,.5);


    }
});




new PHENIX();

