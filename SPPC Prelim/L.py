other_hours, other_mins = (int(x) for x in input().split())
earth_contact_h, earth_contact_m = (int(x) for x in input().split())
other_contact_h, other_contact_m = (int(x) for x in input().split())

earth_contact = earth_contact_h * 60 + earth_contact_m
other_contact = other_contact_h * other_mins + other_contact_m

earth_d, earth_h, earth_m = (int(x) for x in input().split())
earth_meeting = earth_d * 1440 + earth_h * 60 + earth_m
meeting_rel = earth_meeting - earth_contact

other_meeting = meeting_rel + other_contact
other_d = other_meeting // (other_hours * other_mins)
other_meeting %= (other_hours * other_mins)
other_h = other_meeting // other_mins
other_meeting %= other_mins
other_m = other_meeting

print(f"{other_d} {other_h} {other_m}")

