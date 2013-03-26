this.angle = 0;

//--------------------------------------------------------------
function setup()
{
}

//--------------------------------------------------------------
function draw(w,h)
{
	this.nb = 10;
	this.step = w/this.nb;
	of.SetColor(255,255,255);
	for (var i=0;i<nb;i++){
		var d = 120*0.5*(1+Math.cos(Math.PI/180*(angle+i*10)));
		of.Ellipse(i*step,h/2,d,d);
	}
}

//--------------------------------------------------------------
function update(dt)
{
	this.angle += getClientBass(0,0)*10;
}
