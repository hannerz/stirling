def do_observe(obj, target="here"):
    '''
    usage: observe [target]
        returns the description of the target, defaulting to current environment
    '''
    if target is "here":
        obj.debug(type(obj.environment.__name__))
        obj.tell(obj.envirtonment.desc())
    else:
        obj.tell("Sorry, this command can't handle arguments yet")

