Handle<Value> Include(const Arguments& args) {
    for (int i = 0; i < args.Length(); i++) {
        String::Utf8Value str(args[i]);

        // load_file loads the file with this name into a string,
        // I imagine you can write a function to do this :)
        std::string js_file = load_file(*str);

        if(js_file.length() > 0) {
            Handle<String> source = String::New(js_file.c_str());
            Handle<Script> script = Script::Compile(source);
            return script->Run();
        }
    }
    return Undefined();
}

Handle<ObjectTemplate> global = ObjectTemplate::New();

global->Set(String::New("include"), FunctionTemplate::New(Include));