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
		limit.append (@shipping = new Popper 'shipping').popper
		limit.append (@view = new Popper 'view', 'right').popper

		@view.add new Option
		1

class Popper
	constructor: (@name, @class = '') ->
		@popper = $ "<div class=\"popper #{@class}\">#{@name}</div>"

	add: (item) ->
		options.push new Option

class Option
	constructor: (@name = 'an option') ->
		;



root.Overlay = Overlay
root.js = js