// Generated by CoffeeScript 1.10.0
(function() {
  var BlockChooser, Clicky, Item, Notice, Overlay, Popper, Q, Tooltip, Value, js, root,
    extend = function(child, parent) { for (var key in parent) { if (hasProp.call(parent, key)) child[key] = parent[key]; } function ctor() { this.constructor = child; } ctor.prototype = parent.prototype; child.prototype = new ctor(); child.__super__ = parent.prototype; return child; },
    hasProp = {}.hasOwnProperty;

  root = typeof exports !== "undefined" && exports !== null ? exports : this;

  if (root.parts == null) {
    root.parts = null;
  }

  js = {
    q: null,
    overlay: null,
    poppers: [],
    jays: {},
    parts: parts,
    part: null
  };

  js.mkq = function() {
    var ref;
    ((ref = js.q) != null ? ref.boom() : void 0) || (js.q = new Q);
    return 1;
  };

  if (typeof app !== "undefined" && app !== null) {
    app.Q = function() {
      var ref;
      ((ref = js.q) != null ? ref.boom() : void 0) || (js.q = new Q);
      return 1;
    };
  }

  js.boot = function() {
    this.jays.limit = $('#limit');
    this.jays.cel = $('.cel');
    this.jays.poppers = $('#poppers');
    this.black = -1 !== document.location.href.indexOf('black');
    if (this.black) {
      this.jays.limit.css('background', 'url(stars.png)');
    }
    this.jays.limit.css('width', typeof app !== "undefined" && app !== null ? app.w : void 0);
    this.jays.limit.css('height', typeof app !== "undefined" && app !== null ? app.h : void 0);
    return 1;
  };

  js.mstats = function() {
    var delta, fps;
    this.jays.stats = $('<div id="stats">');
    fps = $('<div><!--fps: --><div class="value" id="fps">0</div></div>');
    delta = $('<div><!--delta: --><div class="value" id="delta">0</div></div>');
    this.jays.stats.append(fps);
    this.jays.stats.append(delta);
    this.jays.limit.append(this.jays.stats);
    this.jays.fps = $('#fps');
    this.jays.delta = $('#delta');
    return 0;
  };

  js.second = function() {
    this.jays.fps.html(app.fps);
    this.jays.delta.html(app.delta);
    return 0;
  };

  js.mkoverlay = function() {
    var overlay;
    root.overlay = overlay = new Overlay;
    if (typeof app !== "undefined" && app !== null) {
      app.overlay = overlay;
    }
    return 1;
  };

  js.animate = function(timestamp) {
    var i, len, p, ref;
    ref = this.poppers;
    for (i = 0, len = ref.length; i < len; i++) {
      p = ref[i];
      p.update();
    }
    return void 0;
  };

  Q = (function() {
    function Q() {
      this.jays = {};
      this.build();
    }

    Q.prototype.build = function() {
      var ref, ref1;
      this.jays.element = $('<div id="Q"></div>');
      this.jays.element.append('<div class="label">Personal Physical Assistant 111a</div>');
      this.jays.off = $('<div class="off">off</div>');
      this.jays.off.click((function(_this) {
        return function() {
          return _this.boom();
        };
      })(this));
      this.jays.knob = $('<div class="knob">');
      this.jays.knob.append('<div class="x"><div class="xx"><div class="xxx">');
      this.jays.screen = $('<div class="screen">');
      this.jays.boot = $('<div class="boot">');
      this.jays.boot.append('Loading...');
      this.jays.parts = $('<div class="parts">');
      this.mkparts();
      this.jays.screen.append(this.jays.boot);
      this.jays.screen.append(this.jays.parts);
      this.jays.element.append(this.jays.off);
      this.jays.element.append(this.jays.knob);
      this.jays.element.append(this.jays.screen);
      js.jays.cel.empty().append(this.jays.element);
      js.part = $(".part[data-name='" + ((ref = js.part) != null ? ref.name : void 0) + "']");
      if ((ref1 = js.part) != null) {
        ref1.addClass('selected');
      }
      return 1;
    };

    Q.prototype.boom = function() {
      var ref;
      js.part = (ref = js.part) != null ? ref.data('part') : void 0;
      js.q = null;
      this.jays.element.remove();
      return 1;
    };

    Q.prototype.mkparts = function() {
      var i, len, o, part, ref, that;
      that = this;
      ref = js.parts;
      for (i = 0, len = ref.length; i < len; i++) {
        o = ref[i];
        console.log(o);
        part = $("<div data-name=\"" + o.name + "\" class=\"part " + o["class"] + "\"><!--<img src=\"" + o.url + "\" />-->");
        part.data('part', o);
        part.click(function() {
          var jay, ref1;
          jay = $(this);
          if (typeof app !== "undefined" && app !== null) {
            app['part'](jay.data('part').name);
          }
          if ((ref1 = js.part) != null) {
            ref1.removeClass('selected');
          }
          jay.addClass('selected');
          return js.part = jay;
        });
        this.jays.parts.append(part);
      }
      return 1;
    };

    return Q;

  })();

  Overlay = (function() {
    function Overlay() {
      this.build();
    }

    Overlay.prototype.build = function() {
      js.jays.poppers.append((this.shipping = new Popper('shipping')).element);
      js.jays.poppers.append((this.view = new Popper('view', 'right')).element);
      js.jays.poppers.append((this.placeholder = new Popper('placeholder', 'right')).element);
      this.shipping.add(new BlockChooser(''));
      this.view.add(new Clicky({
        name: 'zoom level',
        values: ['3x', '2x', '1x'],
        shortcut: '1-3',
        cpp: 'scale',
        tooltip: 'the default of 3x best brings out the pixels'
      }));
      this.view.add(new Clicky({
        name: 'cross section',
        values: ['on', 'off'],
        shortcut: 'C',
        cpp: 'crossSection',
        tooltip: 'Cross sectioning your craft lets you see through the outer hull'
      }));
      this.view.add(new Value({
        name: 'orientation',
        value: 0,
        suffix: '&deg;',
        cpp: 'orientation'
      }));
      this.view.add(new Clicky({
        name: 'orient',
        values: ['ship', 'free']
      }));
      return 1;
    };

    return Overlay;

  })();

  Tooltip = (function() {
    function Tooltip(o1) {
      this.o = o1;
      this.element = $("<div class=\"tooltip\">" + this.o.o.tooltip + "</div>");
      this.o.element.append(this.element);
      this.o.tooltip = this;
    }

    Tooltip.prototype.rm = function() {
      this.o.tooltip = null;
      this.element.remove();
      return 1;
    };

    return Tooltip;

  })();

  Popper = (function() {
    function Popper(name, _class) {
      this.name = name;
      this["class"] = _class != null ? _class : '';
      this.items = [];
      this.insides = null;
      this.element = $("<div class=\"popper\">");
      this.button = $("<div class=\"button " + this["class"] + "\">" + this.name + "</div>");
      this.element.mouseenter((function(_this) {
        return function() {
          return _this.expire(false);
        };
      })(this));
      this.element.mouseleave((function(_this) {
        return function() {
          return _this.expire(true);
        };
      })(this));
      this.button.click((function(_this) {
        return function() {
          return _this.expand();
        };
      })(this));
      this.element.append(this.button);
      this.time = 0;
      js.poppers.push(this);
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
      if (js.black) {
        return;
      }
      if (yea) {
        this.time = setTimeout((function(_this) {
          return function() {
            return _this.vanish();
          };
        })(this), 300);
      } else {
        clearTimeout(this.time);
      }
      return 1;
    };

    Popper.prototype.vanish = function() {
      if (this.insides == null) {
        return;
      }
      this.insides.detach();
      this.insides = null;
      return 1;
    };

    Popper.prototype.update = function() {
      var i, len, o, ref;
      if (this.insides == null) {
        return;
      }
      ref = this.items;
      for (i = 0, len = ref.length; i < len; i++) {
        o = ref[i];
        o.update();
      }
      return 1;
    };

    return Popper;

  })();

  Item = (function() {
    function Item(o1) {
      var base, base1, base2;
      this.o = o1;
      if ((base = this.o)["class"] == null) {
        base["class"] = '';
      }
      if ((base1 = this.o).suffix == null) {
        base1.suffix = '';
      }
      if ((base2 = this.o).tooltip == null) {
        base2.tooltip = 'Explodes the known universe';
      }
      this.tooltip = null;
      this.element = null;
    }

    Item.prototype.build = function() {
      return 0;
    };

    Item.prototype.register = function() {
      this.element.mouseenter((function(_this) {
        return function() {
          return _this.explain(true);
        };
      })(this));
      this.element.mouseleave((function(_this) {
        return function() {
          return _this.explain(false);
        };
      })(this));
      return 1;
    };

    Item.prototype.explain = function(fuse) {
      var ref;
      if (!this.o.tooltip) {
        return;
      }
      if (fuse && (this.tooltip == null)) {
        this.time = setTimeout((function(_this) {
          return function() {
            return new Tooltip(_this);
          };
        })(this), 500);
      } else {
        clearTimeout(this.time);
        if ((ref = this.tooltip) != null) {
          ref.rm();
        }
      }
      return 1;
    };

    Item.prototype.update = function() {
      return 1;
    };

    return Item;

  })();

  Value = (function(superClass) {
    extend(Value, superClass);

    function Value(o) {
      Value.__super__.constructor.call(this, o);
      this.build();
      this.register();
    }

    Value.prototype.build = function() {
      this.element = $("<div class=\"item " + this.o["class"] + "\">" + this.o.name + ": <div class=\"value\">" + this.o.value + this.o.suffix + "</div></div>");
      this.value = this.element.find('.value');
      return 1;
    };

    Value.prototype.update = function() {
      if (this.o.cpp == null) {
        return;
      }
      console.log("update app " + this.o.cpp + " value /w " + app[this.o.cpp]);
      this.value.html("" + (app[this.o.cpp].toFixed(1)) + this.o.suffix);
      return 1;
    };

    return Value;

  })(Item);

  Clicky = (function(superClass) {
    extend(Clicky, superClass);

    function Clicky(o) {
      Clicky.__super__.constructor.call(this, o);
      this.element = null;
      this.i = 0;
      this.build();
      this.register();
    }

    Clicky.prototype.build = function() {
      var that;
      this.element = $("<div class=\"item clicky " + this.o["class"] + "\">" + this.o.name + ": <div class=\"shortcut\">" + this.o.shortcut + "</div> <div class=\"value\">" + this.o.values[this.i] + "</div></div>");
      this.button = this.element.find('.value');
      that = this;
      this.element.click(function() {
        return that.change(this);
      });
      return 1;
    };

    Clicky.prototype.change = function(j) {
      var value;
      this.i = this.i + 1 === this.o.values.length ? 0 : this.i + 1;
      value = this.o.values[this.i];
      $(j).find('.value').html(value);
      if (this.o.cpp != null) {
        app[this.o.cpp](value);
      }
      return void 0;
    };

    Clicky.prototype.update = function() {
      return 1;
    };

    return Clicky;

  })(Item);

  Notice = (function() {
    function Notice(o) {
      this.text = o.text;
      this.build();
    }

    Notice.prototype.build = function() {
      var close, text, that;
      this.element = $("<div class=\"notice\"></div>");
      text = $("<div class=\"text\">&mdash; " + this.text + " &mdash;</div>");
      close = $("<a class=\"button\" href=\"javascript:;\">Close</a>");
      this.element.append(text);
      this.element.append(close);
      close = this.element.find('.button');
      that = this;
      close.click(function() {
        return that.cleanup();
      });
      js.jays.append(this.element);
      return 1;
    };

    Notice.prototype.cleanup = function() {
      this.element.remove();
      return 1;
    };

    return Notice;

  })();

  BlockChooser = (function() {
    function BlockChooser() {}

    BlockChooser.prototype.build = function() {};

    return BlockChooser;

  })();

  root.Overlay = Overlay;

  root.Q = Q;

  root.js = js;

}).call(this);
