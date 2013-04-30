var TheBoat = Animation.extend({

    setup: function (s) {

        println("-- TheBoat.js -- ");
        this._super();



    },

    update: function (s) {


        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];

            var currentPos  = getSharpyPos(s, i);
            var nextPos     = getSharpyPos(s, i+2);



            lookAt(s, index, nextPos.x, 0, depth);
            lookAt(s, nextIndex, currentPos.x, 0, depth);

        }

        //var pos     = getSharpyPos(s, 14);
        //lookAt(s, 15, pos.x, 0, depth);
        forceLight(s, 15, 0);




    }



});


new TheBoat();




