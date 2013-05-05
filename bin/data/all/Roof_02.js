var Roof_02 = Animation.extend({

    setup: function (s) {

        println("-- Roof_02.js -- ");
        this._super();

        

    },

    update: function (s) {
        
        //
        var pos = getSharpyPos(s, 15);
        lookAt(s, 31, pos.x, pos.y, depth);
        
        var pos = getSharpyPos(s, 31);
        lookAt(s, 15, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 15);
        lookAt(s, 30, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 31);
        lookAt(s, 14, pos.x, pos.y, 0);
        
        
        //
        var pos = getSharpyPos(s, 13);
        lookAt(s, 29, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 29);
        lookAt(s, 13, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 13);
        lookAt(s, 28, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 29);
        lookAt(s, 12, pos.x, pos.y, 0);
        
        
        //
        var pos = getSharpyPos(s, 11);
        lookAt(s, 27, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 27);
        lookAt(s, 11, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 11);
        lookAt(s, 26, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 27);
        lookAt(s, 10, pos.x, pos.y, 0);
        
        
        //
        var pos = getSharpyPos(s, 9);
        lookAt(s, 25, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 25);
        lookAt(s, 9, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 9);
        lookAt(s, 24, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 25);
        lookAt(s, 8, pos.x, pos.y, 0);
        
        
        //
        var pos = getSharpyPos(s, 7);
        lookAt(s, 23, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 23);
        lookAt(s, 7, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 7);
        lookAt(s, 22, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 23);
        lookAt(s, 6, pos.x, pos.y, 0);
        
        
        //
        var pos = getSharpyPos(s, 5);
        lookAt(s, 21, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 21);
        lookAt(s, 5, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 5);
        lookAt(s, 20, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 21);
        lookAt(s, 4, pos.x, pos.y, 0);
        
        
        //
        var pos = getSharpyPos(s, 3);
        lookAt(s, 19, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 19);
        lookAt(s, 3, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 3);
        lookAt(s, 18, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 19);
        lookAt(s, 2, pos.x, pos.y, 0);
        
        
        //
        var pos = getSharpyPos(s, 1);
        lookAt(s, 17, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 17);
        lookAt(s, 1, pos.x, pos.y, depth);

        var pos = getSharpyPos(s, 1);
        lookAt(s, 16, pos.x, pos.y, 0);

        var pos = getSharpyPos(s, 17);
        lookAt(s, 0, pos.x, pos.y, 0);
        

    }



});


new Roof_02();




