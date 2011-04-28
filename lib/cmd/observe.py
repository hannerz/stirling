from stirling.lib.obj.room import Room

def do_observe(obj, target="here"):
    '''
    usage: observe [target]
        returns the description of the target, defaulting to current environment
    '''
    if target is "here":
        obj.tell("Foobar!")
        print(obj.environment)
        obj.tell(obj.environment.desc())
    else:
        obj.tell("Sorry, this command can't handle arguments yet")

