println("-- app.js -- ");

//include("Scripts/libraries/tweening/Tween.js");
include("Scripts/libraries/fieldkit/src/Header.js");
include("Scripts/libraries/fieldkit/src/Class.js");
include("Scripts/libraries/fieldkit/src/math/Math.js");
include("Scripts/libraries/fieldkit/src/math/Vec2.js");
include("Scripts/libraries/fieldkit/src/math/Vec3.js");
include("Scripts/libraries/tween.min.js")

// ----------------------------
// Global variables and functions

var numSharpy = 32;
var leftSharpies = new Array();
var rightSharpies = new Array();
var horizontalSharpies = new Array();

var animations = new Array();
var previewAnimIndex = 0;

var speedPct = 1.0;

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
    println("set preview" + index)
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

    mainAnimation.setup(0);
    previewAnimation.setup(1);
}

function update() {

    mainAnimation.update(0);
    previewAnimation.update(1);
}

var Animation = fk.Class.extend({

    init: function (name) {

        // set name and default for main ( reloading )
        this.name = name;
        animations.push(this);
        mainAnimation = this;

    },

    setup: function () {
    },

    update: function () {
    }
});

// defaults
var mainAnimation = new Animation("empty");
var previewAnimation = new Animation("empty");

setVariables();