var DiagonalRoof = Animation.extend({

    setup: function (s) {

        println("-- DiagonalRoof.js -- ");
        this._super();



    },

    update: function (s) {


        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];

            var currentPos  = getSharpyPos(s, i);
            var nextPos     = getSharpyPos(s, i+1);



            lookAt(s, index, nextPos.x, nextPos.y, 0);
            lookAt(s, nextIndex, currentPos.x, currentPos.y, depth);





        }

        for ( var i=0; i<8; i++)
        forceLight(s, i, 0);


    }



});


new DiagonalRoof();




