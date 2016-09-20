root = exports ? this

root.parts ?= null

js =
	q: null
	overlay: null # bad generic name, change into `context` or `menu`
	poppers: []
	jays: {}
	parts: parts
	part: null

js.mkq = ->
	js.q?.boom() or js.q = new Q
	1

app?.Q = ->
	js.q?.boom() or js.q = new Q
	1


js.boot = ->
	@jays.limit = $ '#limit'
	@jays.cel = $ '.cel'
	@jays.poppers = $ '#poppers'

	@black = -1 isnt document.location.href.indexOf 'black'

	@jays.limit.css 'background', 'url(stars.png)' if @black

	@jays.limit.css 'width', app?.w
	@jays.limit.css 'height', app?.h

	1

js.mstats = ->
	@jays.stats = $ '<div id="stats">'
	fps = $ '<div><!--fps: --><div class="value" id="fps">0</div></div>'
	delta = $ '<div><!--delta: --><div class="value" id="delta">0</div></div>'
	draws = $ '<div><!--draws: --><div class="value" id="draws">0</div></div>'

	@jays.stats.append fps
	@jays.stats.append delta
	@jays.stats.append draws

	@jays.limit.append @jays.stats

	@jays.fps = $ '#fps'
	@jays.delta = $ '#delta'
	@jays.draws = $ '#draws'
	0

js.second = () ->
	@jays.fps.html app.fps
	@jays.delta.html app.delta
	@jays.draws.html app.draws

	0

js.mkoverlay = ->
	root.overlay = overlay = new Overlay
	app?.overlay = overlay
	1

js.animate = (timestamp) ->
	p.update() for p in this.poppers

	undefined

class Q
	constructor: ->
		@jays = {}

		@build()
		;

	build: ->
		@jays.element = $ '<div id="Q"></div>'
		@jays.element.append '<div class="label">Personal Physical Assistant 111a</div>'

		@jays.off = $ '<div class="off">off</div>'
		@jays.off.click => @boom()

		@jays.knob = $ '<div class="knob">'
		@jays.knob.append '<div class="x"><div class="xx"><div class="xxx">'

		@jays.screen = $ '<div class="screen">'

		@jays.boot = $ '<div class="boot">'
		@jays.boot.append 'Loading...'

		@jays.parts = $ '<div class="parts">'

		@mkparts()

		@jays.screen.append @jays.boot
		@jays.screen.append @jays.parts

		@jays.element.append @jays.off
		@jays.element.append @jays.knob
		@jays.element.append @jays.screen

		js.jays.cel.empty().append @jays.element


		js.part = $ ".part[data-name='#{js.part?.name}']"
		js.part?.addClass 'selected'
		1

	boom: ->
		js.part = js.part?.data 'part'
		js.q = null
		@jays.element.remove()
		1

	mkparts: ->
		that = this

		for o in js.parts
			console.log o
			part = $ "<div data-name=\"#{o.name}\" class=\"part #{o.class}\"><!--<img src=\"#{o.url}\" />-->"
			part.data 'part', o

			part.click ->
				jay = $ this
				app?['part']?(jay.data('part').name)#
				js.part?.removeClass 'selected'
				jay.addClass 'selected'
				js.part = jay

			@jays.parts.append part

		# js.part?.addClass 'selected'

		1

class Overlay
	constructor: ->

		@build()
		;

	build: ->
		# js.jays.poppers.append (@shipping = new Popper 'Shipping').element
		js.jays.poppers.append (@view = new Popper 'View', 'right').element
		js.jays.poppers.append (@placeholder = new Popper 'Something', 'right').element

		# @shipping.add new BlockChooser ''

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
		return

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

		@element.mouseenter => @expire false
		@element.mouseleave => @expire true

		@button.click => @expand()

		@element.append @button

		@time = 0

		js.poppers.push this
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

		if yea
			@time = setTimeout =>
				@vanish()
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
		@o.tooltip ?= 'Explodes the known universe'

		@tooltip = null

		@element = null
		;

	# @Overriden
	build: -> 0

	register: ->
		@element.mouseenter => @explain true
		@element.mouseleave => @explain false
		1

	explain: (fuse) ->
		return unless @o.tooltip

		if fuse and not @tooltip?
			@time = setTimeout =>
				new Tooltip this
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

		@before = null

		@build()

		@register()
		;

	build: ->
		@element = $ "<div class=\"item #{@o.class}\">#{@o.name}: <div class=\"value\">#{@o.value}#{@o.suffix}</div></div>"

		@value = @element.find '.value'
		1

	# @Override
	update: ->
		return unless @o.cpp?

		val = app.valuez[@o.cpp].toFixed 1

		return if val is @before

		@before = val

		console.log "updating #{@o.cpp}"

		@value.html "#{val}#{@o.suffix}"
		1

class Clicky extends Item
	constructor: (o) ->

		super o

		@element = null

		@i = o.values.indexOf app?.valuez[o.cpp]
		@i = 0 if not @i? or -1 is @i

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

		js.jays.append @element
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
root.Q = Q # for debug
root.js = js