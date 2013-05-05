var TheMask = Animation.extend({

    setup: function (s) {

        println("-- The Mask.js -- ");
        this._super();



    },

    update: function (s) {


        for ( var i=0; i<32; i+=2) {

            var index       = horizontalSharpies[i];
            var currentPos  = getSharpyPos(s,  i % 32);
            lookAt(s, i, currentPos.x, 0, depth);

            var currentPos  = getSharpyPos(s,  i % 8);
            lookAt(s, i+1, currentPos.x, 0, depth/2);

        }


    }



});


new TheMask();




