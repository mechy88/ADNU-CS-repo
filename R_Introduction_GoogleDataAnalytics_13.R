# Annotating and Saving
library("tidyverse")
library("ggplot2")

hotel_bookings <- read.csv("hotel_bookings.csv")

start_range <- min(hotel_bookings$arrival_date_year)
end_range <- max(hotel_bookings$arrival_date_year)

ggplot(data = hotel_bookings) +
  geom_bar(mapping = aes(x = market_segment)) +
  facet_wrap(~hotel) +
  labs(title = "Market Segment Bookings", 
       caption = paste0("Data from ", start_range, " to ", end_range),
       x = "Market Segment",
       y = "Number of Bookings")

ggsave("bookings_graph.png",
       width = 16,
       height = 8)