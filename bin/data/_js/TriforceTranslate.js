var TriforceTranslate = Animation.extend({

    setup: function (s) {

        println("-- TriforceTranslate.js -- ");
        this._super();



    },

    update: function (s) {


        var posLeft = getSharpyPos(s, 31);
        var posRight = getSharpyPos(s, 15);

        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];


            lookAt(s, index, posLeft.x, posLeft.y, depth);
            lookAt(s, nextIndex, posRight.x, posRight.y, depth);

            posLeft.x += 100;
            posRight.x += 100;


        }




    }



});


new TriforceTranslate();




