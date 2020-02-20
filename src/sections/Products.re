[@react.component]
let make = () => {
  MaterialUi.(
    <Section
      id="products"
      title="Products I've worked on."
      overline="Contributions"
      textAlign=`center>
      <Grid container=true spacing=V2>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard href="https://merlinlabs.gg" image="images/maybe.png" />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard
            href="https://www.conciergeauctions.com/"
            image="images/logo-box-concierge-auctions.png"
          />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard
            image="images/dawson.png"
            href="https://thedawsonacademy.com"
          />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard
            href="https://acmedical.org"
            image="images/americlerkships.png"
          />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard href="https://vfxcreates.com" image="images/sc.png" />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard href="https://vfxcreates.com" image="images/next.png" />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard href="https://vfxcreates.com" image="images/react.png" />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard
            href="https://vfxcreates.com"
            image="images/nodejslogo.png"
          />
        </Grid>
        <Grid item=true xs=V12 sm=V4>
          <LogoCard href="https://vfxcreates.com" image="images/graphql.png" />
        </Grid>
      </Grid>
    </Section>
  );
};