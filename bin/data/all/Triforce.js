var Triforce = Animation.extend({

    setup: function (s) {

        println("-- Triforce.js -- ");
        this._super();



    },

    update: function (s) {


        var posLeft = getSharpyPos(s, 31);
        //lookAt(s, 0, pos.x, pos.y, depth);

        var posRight = getSharpyPos(s, 15);
        //lookAt(s, 16, pos.x, pos.y, depth);


        for ( var i=0; i<32; i+=2) {



            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];


            lookAt(s, index, posLeft.x, posLeft.y, depth);
            lookAt(s, nextIndex, posRight.x, posRight.y, depth);


        }




    }



});


new Triforce();




