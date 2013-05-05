println("-- app.js -- ");
include("Scripts/libraries/fieldkit/src/Header.js");
include("Scripts/libraries/fieldkit/src/Class.js");
include("Scripts/libraries/fieldkit/src/math/Math.js");
include("Scripts/libraries/fieldkit/src/math/Vec2.js");
include("Scripts/libraries/fieldkit/src/math/Vec3.js");
include("Scripts/libraries/tween.min.js")
include("Scripts/libraries/SimplexNoise.js")
include("Scripts/libraries/EasedPct.js")


// ----------------------------
// Global variables and functions

var numSharpy           = 32;
var leftSharpies        = new Array();
var rightSharpies       = new Array();
var horizontalSharpies  = new Array();

var animations          = new Array();
var previewAnimIndex    = 0;

var width               = getWidth();
var height              = getHeight();
var depth               = getDepth();

var numFrame            = 0;
var totalFrame          = 0;
var animProgress        = 0.0;

var speedPct            = 1.0;
var timeMillis          = 0.0;

var tempname            = "";

function getSharpyPos (s, index) {

    var x = getPosX(s, index);
    var y = getPosY(s, index);
    var z = getPosZ(s, index);

    return new Object({x:x, y:y, z:z});

}

function setVariables() {

    for (var i = 0; i < 2; i++) {

        for (var j = 0; j < 16; j++) {

            var index = i * 16 + j;

            if (i == 0)
                leftSharpies.push(index);
            else
                rightSharpies.push(index);
        }

    }

    for (var j = 0; j < 16; j++) {

        for (var i = 0; i < 2; i++) {

            var index = i * 16 + j;
            horizontalSharpies.push(index);

        }

    }

}

function normalize(val, max) {

    return val / max;

}

function radians(deg) {
    return deg * Math.PI / 180;
}

function setPreviewAnim(index) {
    previewAnimIndex = index;
    previewAnimation = animations[index];

}

function nextPreviewAnim() {

    previewAnimIndex++;
    if (previewAnimIndex == animations.length)
        previewAnimIndex = 0;
    setPreviewAnim(previewAnimIndex);

}

// Effects -------------------------------------

function strobGobo(object) {
    object.gobo = Math.random();

}

function strob(object) {
    object.gobo = Math.random();
    object.brt = Math.random();

}

// -------------------------------------

function setup() {

    if(!mainAnimation) return;

    mainAnimation.setup(0);
    if(previewAnimation)previewAnimation.setup(1);
}



function update(speed, timeMs) {

    if(!mainAnimation) return;

    TWEEN.update();

    speedPct        = speed;
    timeMillis      = timeMs;

    numFrame        = getCurrentAnimFrame();
    totalFrame      = getCurrentTotalFrames();
    animProgress    =  numFrame / totalFrame;

    mainAnimation.update(0);
    if(previewAnimation)previewAnimation.update(1);

}

// this function is used at launch to define filename via OF
// Sadly there's no way to get the filename directly from .js
// so I store in temp var :/
function setName (name) {

    tempname = name;
}

function getCurrentPreviewName () {

    return previewAnimation.name;

}

function addAnim(anim) {

    // check if anim already exists
    // is yes, replace it

    var exists = false;
    for ( var i=0; i<animations.length; i++) {

        if(animations[i].name == anim.name) {
            animations[i] = anim;
            exists = true;
            break;

        }

    }

    if(!exists)
        animations.push(anim);


}

var Animation = fk.Class.extend({


    init: function () {

        // set name and default for main ( reloading )

        if( null == this.name ) {

            this.name = tempname;
            println("set anim name " + tempname)
        }


        addAnim(this);
        mainAnimation = this;


    },

    setup: function (s) {

        // set everything to default if not defined
        for (var i = 0; i < numSharpy; i++) {

            setOrientation  (s, i, 0 , 0, 0);
            setGobo         (s, i, 1.0);
            //forceLight      (s, i, 1.0);

        }

    },

    update: function () {




    }
});

// defaults
var mainAnimation = new Animation("");
var previewAnimation = null;

setVariables();