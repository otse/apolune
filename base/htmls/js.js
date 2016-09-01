// Generated by CoffeeScript 1.10.0
(function() {
  var Clicky, Item, Overlay, Popper, Value, js, limit, overlay, queer, root;

  root = typeof exports !== "undefined" && exports !== null ? exports : this;

  js = {};

  queer = {};

  overlay = null;

  limit = 0;

  js.boot = function() {
    limit = $('#limit');
    return 1;
  };

  js.mstats = function() {
    var delta, fps;
    queer.stats = $('<div id="stats">');
    fps = $('<div>fps: <div class="value" id="fps">0</div></div>');
    delta = $('<div>delta: <div class="value" id="delta">0</div></div>');
    queer.stats.append(fps);
    queer.stats.append(delta);
    $('#limit').append(queer.stats);
    queer.fps = $('#fps');
    queer.delta = $('#delta');
    return 0;
  };

  js.second = function() {
    queer.fps.html(app.fps);
    queer.delta.html(app.delta);
    return 0;
  };

  js.overlay = function() {
    root.overlay = overlay = new Overlay;
    if (typeof app !== "undefined" && app !== null) {
      app.overlay = overlay;
    }
    return 1;
  };

  Overlay = (function() {
    function Overlay() {
      this.build();
    }

    Overlay.prototype.build = function() {
      limit.append((this.shipping = new Popper('shipping')).element);
      limit.append((this.view = new Popper('view', 'right')).element);
      this.view.add(new Clicky({
        name: 'zoom level',
        values: ['3x', '2x', '1x'],
        cpp: 'scale'
      }));
      this.view.add(new Clicky({
        name: 'cross section',
        values: ['on', 'off']
      }));
      this.view.add(new Clicky({
        name: 'orient',
        values: ['ship', 'free']
      }));
      return 1;
    };

    return Overlay;

  })();

  Popper = (function() {
    function Popper(name, _class) {
      var that;
      this.name = name;
      this["class"] = _class != null ? _class : '';
      this.items = [];
      this.insides = null;
      this.element = $("<div class=\"popper\">");
      this.button = $("<div class=\"button " + this["class"] + "\">" + this.name + "</div>");
      that = this;
      this.element.mouseenter(function() {
        return that.expire(false);
      });
      this.element.mouseleave(function() {
        return that.expire(true);
      });
      this.button.click(function() {
        return that.expand();
      });
      this.element.append(this.button);
      this.time = 0;
    }

    Popper.prototype.add = function(item) {
      this.items.push(item);
      return 1;
    };

    Popper.prototype.expand = function() {
      var i, len, o, ref;
      this.insides = $('<div class="insides">');
      ref = this.items;
      for (i = 0, len = ref.length; i < len; i++) {
        o = ref[i];
        this.insides.append(o.element);
      }
      this.element.append(this.insides);
      return 1;
    };

    Popper.prototype.expire = function(yea) {
      var that;
      that = this;
      if (yea) {
        this.time = setTimeout(function() {
          return that.vanish();
        }, 300);
      } else {
        clearTimeout(this.time);
      }
      return 0;
    };

    Popper.prototype.vanish = function() {
      if (this.insides == null) {
        return;
      }
      this.insides.detach();
      this.insides = null;
      return 0;
    };

    return Popper;

  })();

  Item = (function() {
    function Item(o) {
      this.name = o.name;
      this.element = $("<div><div class=\"item " + this["class"] + "\">" + this.name + "</div></div>");
    }

    return Item;

  })();

  Value = (function() {
    function Value(o) {
      this.name = o.name;
      this.value = o.value;
      this.element = null;
      this.build();
    }

    Value.prototype.build = function() {
      this.element = $("<div><div class=\"item " + this["class"] + "\">" + this.name + " <div class=\"value\">" + this.value + "</div></div></div>");
      return 1;
    };

    return Value;

  })();

  Clicky = (function() {
    function Clicky(o) {
      this.name = o.name;
      this.values = o.values;
      this.cpp = o.cpp;
      this.element = null;
      this.i = 0;
      this.build();
    }

    Clicky.prototype.build = function() {
      var that;
      this.element = $("<div><div class=\"item clicky " + this["class"] + "\">" + this.name + " <div class=\"value\">" + this.values[this.i] + "</div></div></div>");
      this.button = this.element.find('.value');
      that = this;
      this.button.click(function() {
        return that.change(this);
      });
      return 1;
    };

    Clicky.prototype.change = function(j) {
      var value;
      this.i = this.i + 1 === this.values.length ? 0 : this.i + 1;
      value = this.values[this.i];
      $(j).html(value);
      if (this.cpp != null) {
        app[this.cpp](value);
      }
      return void 0;
    };

    return Clicky;

  })();

  root.Overlay = Overlay;

  root.js = js;

}).call(this);
