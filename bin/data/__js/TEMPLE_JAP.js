var TEMPLE_JAP = Animation.extend({

    setup: function (s) {

        println("-- TEMPLE_JAPjs -- ");
        this._super();

    },

    update: function (s) {
    
    lookAt(s, 0, 850,0, depth);
    lookAt(s, 16, 850,0, depth);
    lookAt(s, 3, 850,0, depth);
    lookAt(s, 19, 850,0, depth);
    lookAt(s, 3, 850,0, depth);
    lookAt(s, 19, 850,0, depth);
    lookAt(s, 7, 850,0, depth);
    lookAt(s, 23, 850,0, depth);
    lookAt(s, 11, 850,0, depth);
    lookAt(s, 27, 850,0, depth);
    lookAt(s, 31, 850,0, depth);
    lookAt(s, 15, 850,0, depth);

            setOrientation(s, 30, 0,-90, 0);
            setOrientation(s, 14, 0,90, 0);
            setOrientation(s, 28, 0,-90, 0);
            setOrientation(s, 12, 0,90, 0);
            setOrientation(s, 26, 0,-90, 0);
            setOrientation(s, 10, 0,90, 0);
            setOrientation(s, 24, 0,-90, 0);
            setOrientation(s, 8, 0,90, 0);
            setOrientation(s, 22, 0,-90, 0);
            setOrientation(s, 6, 0,90, 0);
            setOrientation(s, 20, 0,-90, 0);
            setOrientation(s, 4, 0,90, 0);
            setOrientation(s, 18, 0,-90, 0);
            setOrientation(s, 2, 0,90, 0);
    
        }
});


new TEMPLE_JAP();


