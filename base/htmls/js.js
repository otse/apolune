queer = {}

function mstats() {
	queer.stats = $('<div id="stats">');
	fps = $('<div>fps: <div class="value" id="fps">0</div></div>')
	delta = $('<div>delta: <div class="value" id="delta">0</div></div>')

	queer.stats.append(fps);
	queer.stats.append(delta);

	$('#limit').append(queer.stats);

	queer.fps = $('#fps')
	queer.delta = $('#delta')

}

function sfps(v) {
	queer.fps.html(v);
}

function sdelta(v) {
	queer.delta.html(v);
}

function second() {
	sfps(app.fps);
	sdelta(app.delta);
}