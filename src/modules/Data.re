type skill = [ | `leader | `engineer | `architect | `performance];

module Company = {
  type t = [
    | `hsoa
    | `concierge
    | `lyntonweb
    | `studiobee
    | `renner
    | `freelance
  ];
  let to_string = company =>
    switch (company) {
    | `hsoa => "HomeServices of America"
    | `concierge => "Concierge Auctions"
    | `lyntonweb => "LyntonWeb"
    | `studiobee => "The Studio Bee"
    | `renner => "Renner Technologies"
    | `freelance => "Freelance"
    };
};

module Achivement = {
  type t = {
    primary: string,
    secondary: string,
    company: Company.t,
    skills: array(skill),
  };
};

module CareerEntry = {
  type t = {
    title: string,
    company: Company.t,
    image: string,
    start: string,
    end_: string,
    link: option(string),
    description: string,
  };
};

module PortfolioEntry = {
  type t = {
    title: string,
    subtitle: string,
    image: string,
    company: Company.t,
  };
};

module Recommendation = {
  type t = {
    from: string,
    title: string,
    company: Company.t,
    relationship: string,
    linkedin: string,
    date: string,
    image: string,
    text: string,
  };
};

let portfolio: array(PortfolioEntry.t) = [|
  {
    title: "Concierge Auctions",
    subtitle: "Web application built with Node, React. Relay and GraphQL",
    image: "images/concierge.png",
    company: `concierge,
  },
  {
    title: "HomeServices of America",
    subtitle: "SaaS platform built with Node, React, Apollo and GraphQL",
    image: "images/hsoa.png",
    company: `hsoa,
  },
  {
    title: "Americlerkships",
    subtitle: "Web application built with React, Salesforce and WordPress",
    image: "images/acmedical.png",
    company: `freelance,
  },
|];

let achievements: array(Achivement.t) = [|
  {
    primary: "Implemented Multi-tenant configuration system",
    secondary: "After launching our first customer on our platform we had to focus on how we scaled the product to more than one customer. We had always built with that intent in mind, but it wasn't until we gave it every ounce of focus did we cross the chasm between one and two customers. During this time I implemented the core of our multi-tenant configuration system that allowed us to go from one site to seven in just under a week.",
    company: `hsoa,
    skills: [|`engineer, `architect|],
  },
  {
    primary: "Led Adoption of the Collaborative Operating System",
    secondary: "One of my proudest moments as a leader was leading the team towards a fully collaborative style of decision making. I faced personal challenges along the way as I changed my leadership tact, and started focusing on driving ownership and alignment above even my own ideas and solutions. The result has been phenomenal, solutions are not only better but everyone understands the why behind them.",
    company: `hsoa,
    skills: [|`leader|],
  },
  {
    primary: "Launched First Brokerage on our Platform",
    secondary: "There is nothing quite like launching your product for the first time. Our goal with the platform was to reach feature parity with a brokerage so that we could replace their technology, this did not give us a lot of room to budge on scope. As a result we were running behind schedule and our small team was frantically fixing bugs and polishing features. Getting everyone moving in the same direction, and inspiring my team by being right there  with them, squashing bugs, was exhilarating and deeply rewarding.",
    company: `hsoa,
    skills: [|`leader, `engineer|],
  },
  {
    primary: "Helped fix a memory leak in Next.js and React",
    secondary: "One of the bugs that was holding up our first product launch was a pretty massive memory leak. All of the engineering teams were occupied fixing other bugs or resolving the last acceptance criteria for features needed for launch, so I took on the memory leak. My journey led me all the way down into the React internals and I worked with the React and Next.js teams to identify the source of the memory leak. A new version of Next.js and React were released that patched the issue and we were able to launch without a hitch.",
    company: `hsoa,
    skills: [|`engineer, `performance|],
  },
|];

let careerHistory: array(CareerEntry.t) = [|
  {
    title: "Director of Software Engineering",
    company: `hsoa,
    image: "images/hsoa2.png",
    start: "Oct 2017",
    end_: "Present",
    link: Some("https://www.homeservices.com"),
    description: "Led the company in a mission to build a national real estate portal SaaS platform, and consolidate the myriad of technology stacks of the brokerages under the HomeServices umbrella.",
  },
  {
    title: "Director of Software Engineering",
    company: `concierge,
    image: "images/cakey.png",
    start: "Sept 2014",
    end_: "Oct 2017",
    link: Some("https://www.conciergeauctions.com"),
    description: "Led the company towards adopting a custom technology platform, including designing and implementing core architecture and user facing features.",
  },
  {
    title: "Lead Web Developer",
    company: `lyntonweb,
    image: "images/lwlogo.png",
    start: "Nov 2012",
    end_: "Aug 2014",
    link: Some("https://www.lyntonweb.com"),
    description: "Led the development team, providing feedback and guidance as well as implementing new integrations and technology to allow the company to take on new clients.",
  },
  {
    title: "Web Developer",
    company: `studiobee,
    image: "images/missingwork.svg",
    start: "Jan 2010",
    end_: "Nov 2012",
    link: None,
    description: "Operated as the principle backend developer and web developer. Responsible for implementing designs from photoshop files and setting up backend support.",
  },
  {
    title: "Web Developer",
    company: `renner,
    image: "images/missingwork.svg",
    link: None,
    start: "2010",
    end_: "2011",
    description: "Operated as web designer and developer for this computer repair and custom build shop in Fairview Heights, Illinois.",
  },
|];

[@genType]
let recommendations: array(Recommendation.t) = [|
  {
    from: "Marta Poling",
    title: "Software Engineering Manager",
    company: `hsoa,
    relationship: "Marta was our very first Software Engineer Manager at HomeServices of America, and was a more than capable leader and engineer.",
    linkedin: "https://www.linkedin.com/in/martahjohnson/",
    date: "Jan 24, 2020",
    image: "https://media-exp1.licdn.com/dms/image/C4E03AQH7jqBHESJ-bw/profile-displayphoto-shrink_100_100/0?e=1585785600&v=beta&t=Af6jIbUOK_M0U7tF2WfuzehF8bhJJV6HLV6F41ZBcAA",
    text: "Brad has been my most valuable mentor over the past four years and I would highly recommend him for both leadership and deeply technical roles.
    As a leader, Brad is committed to instilling and maintaining a culture of best practices and high standards. He advocates passionately for what he considers the best path forward but also believes in getting buy-in from his team. He is quick to see the advantage to his team and the company of adopting new technology and eager to mentor others on how to leverage it effectively. Brad is an inspirational leader and a bulwark of a healthy developer experience.
    Even after taking on substantial managerial responsibilities, Brad kept himself up to date on the evolution of the application and its dependencies and remained the final authority on solving thorny issues. He is as comfortable diving into the codebase himself as he is delegating work and mentoring others. The impressive breadth and depth of his theoretical and practical knowledge of modern application development has been instrumental to the development of our product and team.",
  },
  {
    from: "George Nickas",
    title: "Senior Software Engineer",
    company: `hsoa,
    relationship: "Marta was our very first Software Engineer Manager at HomeServices of America, and was a more than capable leader and engineer.",
    linkedin: "https://www.linkedin.com/in/george-nickas-61a52ba/",
    date: "Jan 23, 2020",
    image: "https://media-exp1.licdn.com/dms/image/C4D03AQEbta2duSdLnw/profile-displayphoto-shrink_100_100/0?e=1585785600&v=beta&t=s5KQ165EJqtsqScr4punqZHDSLroZ4yOR0LIu7qm2hM",
    text: "I've been in web development for 25 years, as a Senior Software Engineer for 22 of them, since the dotcom era, and I've been under a lot of managers -- and Brad is definitely in the top tier. Knowledgeable, patient, respectful and encouraging, eloquent, and wicked smart.
    He somehow multitasked between directing our development team -- paying close attention to what we're doing and how we're coding, and working for improvements in our processes, i.e. integrating our needs as engineers with what the company needs us to produce -- as well as contributing almost the amount of code as a full-time engineer. I suspect there's a clone involved somewhere.
    Brad was *definitely* not one of those managers who coded back in the day, and feels like they're still current but aren't really: he is a subject matter expert in everything I've seen him do here, and I learned much from his peer-reviewed code, his help when he's peer-reviewed mine, and when we've pair programmed.
    It was a pleasure to work with Brad, and I wish it hadn't ended so soon, when our office was unfortunately closed. ",
  },
  {
    from: "Ari Frankel",
    title: "Software Engineer",
    company: `hsoa,
    relationship: "Marta was our very first Software Engineer Manager at HomeServices of America, and was a more than capable leader and engineer.",
    linkedin: "https://www.linkedin.com/in/ari-frankel/",
    date: "Jan 21, 2020",
    image: "https://media-exp1.licdn.com/dms/image/C5603AQHQ4uJOG-lyuA/profile-displayphoto-shrink_100_100/0?e=1585785600&v=beta&t=LTubI9nNkkDMBRphhRVy13NyDcmY-wv84yl8qbKSQQI",
    text: "Brad and I became acquainted while I was a Technical Mentor (Hacker in Residence) at Hack Reactor (now Galvanized). He delivered an introduction to GraphQL to a room full of eager students and faculty. His reputation as an established contributor to and evangelist of Open Source JS preceded him. After the talk Brad was kind enough to exchange contact information with me and we continued a conversation about GraphQL and other open source JS tech of interest to us both. A couple months later Brad and I were working together at Concierge Auctions.
    As in fledgeling open source technology, so-to with fledgeling developers, Brad has a proven passion for cultivating the people and projects he believes in. Over my years working with Brad, I learned that for Brad to take professional interest in me was more than a contractual arrangement, it was a commitment to my growth as an engineer. This manifested in countless conversations, thorough code reviews, technical and non-technical mentorship, and a constant sense that \"he had my back.\"
    I appreciate Brad for all of that. He has played an important role in my development in to the engineer that I am today.",
  },
|];