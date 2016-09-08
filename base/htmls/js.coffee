root = exports ? this

js = {}
poppers = []
queer = {}
overlay = null

limit = 0


js.boot = ->
	limit = $ '#limit'

	js.black = -1 isnt document.location.href.indexOf 'black'

	limit.css 'background', 'black' if js.black

	limit.css 'width', app?.w
	limit.css 'height', app?.h

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
		limit.append (@placeholder = new Popper 'placeholder', 'right').element

		@shipping.add new BlockChooser ''

		@view.add new Clicky
				name: 'zoom level'
				values: ['3x', '2x', '1x']
				shortcut: '1-3'
				cpp: 'scale'
				tooltip: 'the default of 3x best brings out the pixels'

		@view.add new Clicky
				name: 'cross section'
				values: ['on', 'off']
				shortcut: 'C'
				cpp: 'crossSection'
				tooltip: 'Cross sectioning your craft lets you see through the outer hull'

		@view.add new Value
				name: 'orientation'
				value: 0
				suffix: '&deg;'
				cpp: 'orientation'

		@view.add new Clicky
				name: 'orient'
				values: ['ship', 'free']

		# new Notice text: "You arrive in space. The maelstrom in the distance is whirling. Worlds are far apart, but you can build a craft."

		1

class Tooltip
	constructor: (@o) ->
		@element = $ "<div class=\"tooltip\">#{@o.o.tooltip}</div>"

		@o.element.append @element

		@o.tooltip = this # unuse

		;

	rm: ->
		@o.tooltip = null
		@element.remove()
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
		return if js.black

		that = this
		if yea
			@time = setTimeout ->
				that.vanish()
			, 300
		else
			clearTimeout @time
		1

	vanish: ->
		return unless @insides?
		@insides.detach()
		@insides = null
		1

	update: ->
		return unless @insides?
		
		o.update() for o in @items
		1

class Item
	constructor: (@o) ->
		@o.class ?= ''
		@o.suffix ?= ''
		@o.tooltip ?= 'Possibly explodes the known universe'

		@tooltip = null

		@element = null
		;

	# @Overriden
	build: -> 0

	register: ->
		that = this

		@element.mouseenter -> that.explain true
		@element.mouseleave -> that.explain false
		1

	explain: (fuse) ->
		return unless @o.tooltip

		that = this

		if fuse and not @tooltip?
			@time = setTimeout ->
				new Tooltip that
			, 500
		else
			clearTimeout @time
			@tooltip?.rm()

		1

	# @Overriden
	update: -> 1

class Value extends Item
	constructor: (o) ->
		
		super o

		@build()

		@register()
		;

	build: ->
		@element = $ "<div class=\"item #{@o.class}\">#{@o.name}: <div class=\"value\">#{@o.value}#{@o.suffix}</div></div>"

		@value = @element.find '.value'
		1

	# @Override
	update: ->
		return unless @cpp?

		console.log "update app #{@o.cpp} value /w #{app[@o.cpp]}"

		@o.value.html "#{app[@o.cpp].toFixed 1}#{@o.suffix}"
		1

class Clicky extends Item
	constructor: (o) ->

		super o

		@element = null

		@i = 0
		@build()

		@register()
		;

	build: ->
		@element = $ "<div class=\"item clicky #{@o.class}\">#{@o.name}: <div class=\"shortcut\">#{@o.shortcut}</div> <div class=\"value\">#{@o.values[@i]}</div></div>"

		@button = @element.find '.value'

		that = this
		@element.click -> that.change this

		1

	change: (j) ->
		@i = if @i + 1 is @o.values.length then 0 else @i + 1
		value = @o.values[@i]
		$(j).find('.value').html value
		app[@o.cpp] value if @o.cpp?
		undefined

	# @Override
	update: ->

		1

class Notice
	constructor: (o) ->
		@text = o.text

		@build()
		;

	build: ->
		# $('.notice').remove()

		@element = $ "<div class=\"notice\"></div>"
		text = $ "<div class=\"text\">&mdash; #{@text} &mdash;</div>"
		close = $ "<a class=\"button\" href=\"javascript:;\">Close</a>"

		@element.append text
		@element.append close

		close = @element.find '.button'

		that = this
		close.click -> that.cleanup()

		$('.cel').append @element
		1

	cleanup: ->
		@element.remove()
		1

class BlockChooser
	constructor: ->
		;

	build: ->
		;


root.Overlay = Overlay
root.js = js