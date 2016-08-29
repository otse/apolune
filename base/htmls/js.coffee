root = exports ? this

js = {}
queer = {}
overlay = null

limit = 0


js.boot = ->
	limit = $ '#limit'
	1

js.mstats = ->
	queer.stats = $ '<div id="stats">'
	fps = $ '<div>fps: <div class="value" id="fps">0</div></div>'
	delta = $ '<div>delta: <div class="value" id="delta">0</div></div>'

	queer.stats.append fps
	queer.stats.append delta

	$('#limit').append queer.stats

	queer.fps = $ '#fps'
	queer.delta = $ '#delta'
	0

js.second = () ->
	queer.fps.html app.fps
	queer.delta.html app.delta
	0

js.overlay = ->
	root.overlay = overlay = new Overlay
	app?.overlay = overlay
	1

class Overlay
	constructor: ->

		@build()
		;

	build: ->
		limit.append (@shipping = new Popper()).popper
		1

class Popper
	constructor: ->
		@popper = $ '<div class="popper">creative menu</div>'

		;



root.Overlay = Overlay
root.js = js