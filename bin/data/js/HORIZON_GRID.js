var HORIZON_GRID = Animation.extend({

    setup: function (s) {

        println("-- HORIZON_GRID.js -- ");
        this._super();



    },

    update: function (s) {

        println(this.name)


        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];
            var speed = speedPct *-230;
            
            
      
            
            
            var pct = normalize(i, 32);
s
            
            var x = 0
            var y =(- height + (pct * height *2))*1.5;
           


            lookAt(s, index, x, y, speed);
            lookAt(s, nextIndex, x, y, speed);
           // forceLight(s,i,0);




        }
        
        
       
        


    }



});


new HORIZON_GRID();

