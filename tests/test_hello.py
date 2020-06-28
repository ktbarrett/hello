import hello


def test_hello():
    assert hello.hello() == "Hello, World!"
    assert hello.hello("Dad") == "Hello, Dad!"


def test_return_answer_to_life():
    assert hello.return_answer_to_life() == 42  # it's not much a secret anymore...
