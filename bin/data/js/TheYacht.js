var TheYacht = Animation.extend({

    setup: function (s) {

        println("-- The Yacht.js -- ");
        this._super();



    },

    update: function (s) {


        for ( var i=0; i<32; i+=2) {





            var currentPos  = getSharpyPos(s, i);
            var nextPos     = getSharpyPos(s, i+2);



            lookAt(s, i, nextPos.x, 0, depth);
            lookAt(s, i + 1, currentPos.x, 0, depth);

        }

        var pos     = getSharpyPos(s, 31);
        lookAt(s, 14, pos.x, 0, depth);





    }



});


new TheYacht();




