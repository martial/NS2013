var CrazyCross = Animation.extend({

    setup: function (s) {

        println("-- Crazy Cross.js -- ");
        this._super();



    },

    update: function (s) {


        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];

            var currentPos  = getSharpyPos(s, i);
            var nextPos     = getSharpyPos(s, i+2);



            lookAt(s, index, nextPos.x, nextPos.y, depth);
            lookAt(s, nextIndex, currentPos.x, currentPos.y, depth);





        }






    }



});


new CrazyCross();




