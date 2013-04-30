var WTF = Animation.extend({

    setup: function (s) {

        println("-- WTF.js -- ");
        this._super();

    },

    update: function (s) {

  for (var i = 0; i < numSharpy; i++) {

            // horizontalSharpies nous renvoie l'index des sharpies, mais mappé à l'envers

            var index = horizontalSharpies[i];
            var angle = ( i< 16) ?  -200 : 150;
            var angle2 = ( i< 32) ?  100 : -1500;

            // afin de mieux comprendre, remplacer index par i

            lookAt(s,index,-1200, angle, depth/2 );
            lookAt(s,i,120, angle2, depth/3 );

            
        }
    }
});


new WTF();


