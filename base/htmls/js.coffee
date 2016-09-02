root = exports ? this

js = {}
poppers = []
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

js.animate = (timestamp) ->
	p.update() for p in poppers

	return

class Overlay
	constructor: ->

		@build()
		;

	build: ->
		limit.append (@shipping = new Popper 'shipping').element
		limit.append (@view = new Popper 'view', 'right').element

		@view.add new Clicky name: 'zoom level', values: ['3x', '2x', '1x'], cpp: 'scale'
		@view.add new Clicky name: 'cross section', values: ['on', 'off']
		@view.add new Value name: 'orientation', value: 0, suffix: '&deg;', cpp: 'orientation'
		@view.add new Clicky name: 'orient', values: ['ship', 'free']
		1

class Popper
	constructor: (@name, @class = '') ->
		@items = []

		@insides = null

		@element = $ "<div class=\"popper\">"
		@button = $ "<div class=\"button #{@class}\">#{@name}</div>"

		that = this
		@element.mouseenter -> that.expire false
		@element.mouseleave -> that.expire true

		@button.click -> that.expand()

		@element.append @button

		@time = 0

		poppers.push this
		;

	add: (item) ->
		@items.push item
		1

	expand: ->
		@insides = $ '<div class="insides">'

		for o in @items
			@insides.append o.element

		@element.append @insides
		1

	expire: (yea) ->
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
		@insides.detach()
		@insides = null
		0

	update: ->
		return unless @insides?
		
		o.update() for o in @items

class Item
	constructor: (o) ->
		@name = o.name

		@element = $ "<div><div class=\"item #{@class}\">#{@name}</div></div>"
		;

	# @ Overriden
	update: ->

		0

class Value extends Item
	constructor: (o) ->
		@name = o.name
		@value = o.value
		@suffix = o.suffix or ''
		@cpp = o.cpp

		@element = null

		@build()
		;

	build: ->
		@element = $ "<div><div class=\"item #{@class}\">#{@name} <div class=\"value\">#{@value}#{@suffix}</div></div></div>"

		@value = @element.find '.value'
		1

	# @Overrides
	update: ->
		return unless @cpp?

		console.log "update app #{@cpp} value /w #{app[@cpp]}"

		@value.html "#{app[@cpp].toFixed 1}#{@suffix}"
		0

class Clicky extends Item
	constructor: (o) ->
		@name = o.name
		@values = o.values
		@cpp = o.cpp

		@element = null

		@i = 0
		@build()
		;

	build: ->
		@element = $ "<div><div class=\"item clicky #{@class}\">#{@name} <div class=\"value\">#{@values[@i]}</div></div></div>"

		@button = @element.find '.value'

		that = this
		@button.click -> that.change this

		1

	change: (j) ->
		@i = if @i + 1 is @values.length then 0 else @i + 1
		value = @values[@i]
		$(j).html value
		app[@cpp] value if @cpp?
		undefined

	# @Override
	update: ->

		0

root.Overlay = Overlay
root.js = js