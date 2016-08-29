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
		limit.append (@shipping = new Popper 'shipping').element
		limit.append (@view = new Popper 'view', 'right').element

		@view.add new Option 'gay'
		1

class Popper
	constructor: (@name, @class = '') ->
		@things = []

		@insides = null

		@element = $ "<div class=\"popper\">"
		@button = $ "<div class=\"button #{@class}\">#{@name}</div>"

		that = this
		@element.mouseenter -> that.expire false
		@element.mouseleave -> that.expire true

		@button.click -> that.expand()

		@element.append @button

		@time = 0
		;

	add: (item) ->
		@things.push new Value 'scale', 3
		@things.push new Value 'cross section', 'on'
		1

	expand: ->
		@insides = $ '<div class="insides">'

		for o in @things
			@insides.append o.element

		@element.append @insides
		1

	expire: (yea) ->
		console.log "expire #{yea}"
		that = this
		if yea
			@time = setTimeout ->
				that.vanish()
			, 300
		else
			clearTimeout @time
		0

	vanish: ->
		return unless @insides?
		@insides.remove()
		@insides = null
		0


class Option
	constructor: (@name = 'an option', @class = '') ->
		@element = $ "<div class=\"option #{@class}\">#{@name}</div>"
		;

class Value
	constructor: (@name = 'a value', @value, @class = '') ->
		@element = null

		@build()
		;

	build: ->
		@element = $ "<div class=\"option #{@class}\">#{@name}: <div class=\"value\">#{@value}</div></div>"
		1



root.Overlay = Overlay
root.js = js