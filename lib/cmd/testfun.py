def do_testfun(obj, *a, **kw):
    '''
    usage: testfun -sHorTArGz --long=arg argument
        simple test function written to help with debugging the 
        command parser
    '''
    print(a, kw)
    obj.tell("You don't have eyes, you can't see\n")
