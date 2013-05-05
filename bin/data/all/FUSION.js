var FUSION = Animation.extend({

    setup: function (s) {

        println("-- FUSION.js -- ");
        this._super();



    },

    update: function (s) {


        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];
            var speed = speedPct *-230;
            
            
      
            
            
            var pct = normalize(i, 32);
s
            
            var x = (- width + (pct * width *2))*2;
            var y = 0;
           


            lookAt(s, index, x, y, speed);
            lookAt(s, nextIndex, x,y, speed);





        }
        
        
       
        


    }



});


new FUSION();

