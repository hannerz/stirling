import logging
logger = logging.getLogger(__name__)
logger.debug('Imported')
>>>>>>> fa8c933f5e8c4c5dec268924cd2b804438fae530

def do_observe(obj, target="here"):
    '''
    usage: observe [target]
        returns the description of the target, defaulting to current environment
    '''
    if target is "here":
        obj.tell("Foobar!")
        print(obj.environment.name())
        obj.tell(obj.environment.desc())
    else:
        obj.tell("Sorry, this command can't handle arguments yet")

