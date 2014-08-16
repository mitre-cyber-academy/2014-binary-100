from twisted.internet import reactor, protocol


class Echo(protocol.Protocol):
    """This is just about the simplest possible protocol"""
    
    def dataReceived(self, data):
        "As soon as any data is received, write it back."
        print repr(data)
        if data.startswith('SSOM'):
            self.transport.write('aSByZWFsbHkgaG9wZSBsaWZlIGdldHMgZWFzaWVyLi4u')
        else:
            self.transport.write('Nope.\n')


def main():
    """This runs the protocol on port 8000"""
    factory = protocol.ServerFactory()
    factory.protocol = Echo
    reactor.listenTCP(51717,factory)
    reactor.run()

# this only runs if the module was *not* imported
if __name__ == '__main__':
    main()
