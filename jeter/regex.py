import re

logs = [
    "192.168.0.1 - - [08/Sep/2012:11:15:00 +0200] \"GET /page2.html HTTP/1.1\" 200 2000 \"http://intranet-if.insa-lyon.fr/page1.html\" \"Mozilla/5.0\"",
    "192.168.0.1 - - [08/Sep/2012:11:37:00 +0200] \"GET /page1.html HTTP/1.1\" 200 1000 \"http://intranet-if.insa-lyon.fr/page2.html\" \"Mozilla/5.0\"",
    "192.168.0.1 - - [08/Sep/2012:12:12:00 +0200] \"GET /page2.html HTTP/1.1\" 200 2000 \"http://intranet-if.insa-lyon.fr/page3.html\" \"Mozilla/5.0\"",
    "192.168.0.1 - - [08/Sep/2012:12:16:00 +0200] \"GET /page3.html HTTP/1.1\" 200 3000 \"http://intranet-if.insa-lyon.fr/page2.html\" \"Mozilla/5.0\"",
    "192.168.0.1 - - [08/Sep/2012:12:16:01 +0200] \"GET /image.jpg HTTP/1.1\" 200 50000 \"http://intranet-if.insa-lyon.fr/page3.html\" \"Mozilla/5.0\"",
    "192.168.0.1 - - [08/Sep/2012:12:59:00 +0200] \"GET /page2.html HTTP/1.1\" 200 2000 \"http://intranet-if.insa-lyon.fr/page1.html\" \"Mozilla/5.0\""
]

log_regex = R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})( - - \[\d{2}\/[a-zA-Z]{3}\/\d{4}:\d{2}:\d{2}:)(\d{2})( )(\+|\-)(\d{4})(]\ )((\")(GET|POST|HEAD|OPTIONS)( ))(\/.+)(\.)(.+)( )(HTTP\/1\.(1|0))(\")( )(\d{3})( )(\d+)( )(\")(http:\/\/intranet\-if.insa-lyon.fr)(.+)(\")( )((\")(.+)(\"))"

for log in logs:
    match = re.search(log_regex, log)
    if match:
        print(f"Hour: {match.group(2)}:{match.group(3)}:{match.group(4)}")
        print(f"GMT Shift: {match.group(5)}{match.group(6)}")
        print(f"Destination: {match.group(7)}")
        print(f"Source: {match.group(8)}")
        print("-------------------------")
