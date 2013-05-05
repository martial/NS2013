var Template = Animation.extend({

    setup: function (s) {

        println("-- Template.js -- ");
        this._super();



    },

    update: function (s) {


        var pos = getSharpyPos(s, 31);

        lookAt(s, 0, -getMouseX(), -getMouseY(), depth)




    }



});


new Template();




